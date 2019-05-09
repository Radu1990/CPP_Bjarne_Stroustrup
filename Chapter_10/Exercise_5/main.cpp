#include <iostream>
#include "std_lib_facilities.h"
#include <limits.h>
#include <unistd.h>

const int not_a_reading = -7777;
const int not_a_month = -1;

constexpr int implausible_min = -200; // temp
constexpr int implausible_max = 200;

struct MyException : std::exception
{
    const char* what() const noexcept override { return "Buggers!"; }
};

// check current working directory
string getexepath() {
    char result[ PATH_MAX ];
    ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
    return std::string( result, (count > 0) ? count : 0 );
}

vector<string>month_input_tbl {
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

vector<string> month_print_tbl = {
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
    if (invalids) error("duplicate readings in month", duplicates);
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

void print_dht (ofstream& ofs, int i, int j, int k, Year& yy) {
    // printing Day, Hour, Temp
    if (yy.month[i].day[j].hour[k] != not_a_reading) {
        ofs << "\t\tDay:" << j << endl;
        ofs << "\t\tHour:" << k << " ";
        ofs << "\t\tTemp:" << yy.month[i].day[j].hour[k] << "\n\n";
    }
}

void print_y (ofstream& ofs, Year& yy) {
    // printing years
    ofs << "Year:" << yy.year << "\n";
}
void print_m (ofstream& ofs, int i, Year& yy) {
    if (yy.month[i].month != not_a_month) {
        ofs << "\tMonth:" << int_to_month(yy.month[i].month) << endl;
    }
}

void print_year(ofstream& ofs, Year& yy) {
    // printing years
    print_y(ofs, yy);
    // printing months
    for (int i=0; i < yy.month.size(); ++i) {
        // write months for year
        print_m(ofs, i, yy);
        // printing days, hours, temp
        for (int j = 0; j < yy.month[i].day.size(); ++j) {
            for (int k = 0; k < yy.month[i].day[j].hour.size(); ++k) {
                print_dht(ofs, i, j, k, yy);
            }
        }
    }
}

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
    cout << "Please enter input file name\n";
    string iname = "../textfiles/input.txt"; // add / change to cin >> iname; if needed
    ifstream ifs {iname};
    if (!ifs) error ("can't open file name \n", iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    // open output file
    cout << "Please enter output file name \n";
    string oname = "../textfiles/output.txt"; // add / change to cin >> oname; if needed
    ofstream ofs {oname};
    if (!ofs) error("can't open output file", oname);

    read_write_years(ifs, ofs);
}
