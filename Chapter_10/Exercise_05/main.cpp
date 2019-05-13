#include <iostream>
#include "std_lib_facilities.h"
#include <limits.h>
#include <unistd.h>

/*
 *  This program takes an input file reads the input format
 *  and outputs the content in an output file with a different format like for eg:
 *  { year 1992 { month jan (1 0 61.5) } { month feb (1 1 64)(2 2 65.2) } }
 *  ----->
 * Year:1992
	Month:January
		Day:1
		Hour:0 		Temp:61.5
 */

const int not_a_reading = -7777;
const int not_a_month = -1;

constexpr int implausible_min = -200; // temp
constexpr int implausible_max = 200;

struct MyException : std::exception
{
    const char* what() const noexcept override { return "Buggers!"; }
};

static vector<string>month_input_tbl {
    "jan", "feb", "mar", "apr",
    "may", "jun", "jul", "aug",
    "sep", "oct", "nov", "dec"
};

int month_to_int (const string& s) {
    // if s is the string of the month
    // return it's index [0:11]
    // else return -1
    for (int i=0; i<12; ++i) {
        if (month_input_tbl[i] == s) {
            return i;
        }
    }
    return -1;
}

static vector<string> month_print_tbl = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
};

string int_to_month(int i) {
    // months [0:11]
    if (i<0 || 12<=i) error ("bad month index\n");
    return month_print_tbl[i];
}


struct Reading {
    int day;
    int hour;
    double temperature;
};

struct Day {
    vector<double> hour {vector<double>(24, not_a_reading)};
};

struct Month { // a month of temperature readings
    int month {not_a_month}; // [0:11] January is 0
    vector<Day> day {32}; // [1:31] one vector of readings per day
    // we waste day[0] to keep the code simple
};

struct Year { // a year of temperature readings, organized by month
    int year{}; // positive == A.D.
    vector<Month> month {12}; // [0:11] January is 0
};

bool is_valid(const Reading& r) {
    // a rough test
    if (r.day < 1 || 31 < r.day) return false;
    if (r.hour < 0 || 23 < r.hour) return false;
    if (r.temperature < implausible_min || implausible_max < r.temperature) return false;
    return true;
}

void end_of_loop(istream& ist, char term, const string& message) {
    if (ist.fail()) { // use term as terminator or separator
        ist.clear();
        char ch;
        if (ist >> ch && ch ==term) return;
        error(message);
    }
}

istream& operator>>(istream& is, Reading& r) {
// read a temperature reading from is into r
// format: (3 4 9.7)
// check format, but don't bother with data validity
    char ch1;
    if (is >>ch1 && ch1!='(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    char ch2;
    int d,h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2!=')') throw MyException{};
    r.day=d;
    r.hour=h;
    r.temperature=t;
    return is;
}

istream& operator>>(istream& is, Month& m) {
    // read a month from is into m
    // format: {month feb ...}
    char ch = 0;
    if (is >>ch && ch!='{') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month") {
        throw MyException{}; // bad start of month
    }
    m.month = month_to_int(mm);
    int duplicates = 0;
    int invalids = 0;
    for (Reading r{}; is >> r;) {
        if (is_valid(r)) {
            // if value is already written (aka != -7777)
            // rewrite and count duplicate
            if (m.day[r.day].hour[r.hour] != not_a_reading) {
                ++duplicates;
            }
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else {
            ++invalids;
        }
    }
    if (invalids) error("invalid readings in month", invalids);
    if (duplicates) error("duplicate readings in month", duplicates);
    end_of_loop(is, '}', "bad end of month");
    return is;
}

istream& operator>>(istream& is, Year& y) {
    // read a year from is into y
    // format: { year 1972 ... }
    char ch;
    is >> ch;
    if (ch!= '{') {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }
    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year") error("bad start of the year!");
    y.year = yy;
    while (true) {
        // write struct m at his position in year
        // (all read from is first into m)
        Month m; // get a clean month each time
        if(!(is >> m)) break;
        y.month[m.month] = m;
    }
    end_of_loop(is, '}', "bad end of year");
    return is;
}
// called by return_month
void return_day(ofstream& ofs, const vector<Day>& dd){
    // printing days, hours, temp
    for (int j = 0; j < dd.size(); ++j) {
        for (int k = 0; k < dd[j].hour.size(); ++k) {
            // printing Day, Hour, Temp
            if (dd[j].hour[k] != not_a_reading) {
                ofs << "\t\tDay:" << j << endl;
                ofs << "\t\tHour:" << k << " ";
                ofs << "\t\tTemp:" << dd[j].hour[k] << "\n\n";
            }
        }
    }
}
// called by print_year
void return_month (ofstream& ofs, const vector<Month>& mm) {
    for (int i = 0; i < mm.size(); ++i) {
        if (mm[i].month != not_a_month) {
            ofs << "\tMonth:" << int_to_month(mm[i].month) << endl;
        }
        return_day(ofs, mm[i].day);
    }
}
// called by print_year
void return_year(ofstream& ofs, Year& yy) {
    // printing years
    ofs << "Year:" << yy.year << "\n";
}
// called by main read_write_years
void print_year(ofstream& ofs, Year& yy) {
    // printing years
    return_year(ofs, yy);
    // printing months
    return_month(ofs, yy.month);
}
// main function for read and write of data
void read_write_years(ifstream& ifs, ofstream& ofs) {
    // read an arbitrary number of years:
    vector<Year> ys;
    while(true) {
        Year y{}; // get a freshly initialized Year each time around
        if (!(ifs>>y)) break;
        ys.push_back(y);
    }
    cout << "read " << ys.size() << " years of readings\n";
    for (Year& y : ys) {
        print_year(ofs,y);
    }
}

int main() {
    // open an input file:
    string iname = "../textfiles/input.txt"; // add / change to cin >> iname; if needed
    ifstream ifs {iname};
    if (!ifs) error ("can't open file name \n", iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    // open output file
    string oname = "../textfiles/output.txt"; // add / change to cin >> oname; if needed
    ofstream ofs {oname};
    if (!ofs) error("can't open output file", oname);

    // read and write files
    read_write_years(ifs, ofs);
}
