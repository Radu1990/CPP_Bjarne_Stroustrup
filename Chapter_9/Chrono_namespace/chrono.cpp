#include "chrono.h"

namespace Chrono {
// member functions definitions
Date::Date(int yy, Month mm, int dd):
    y{yy}, m{mm}, d{dd} {
    if (!is_date(yy, mm, dd)) throw Invalid{};
}

const Date &default_date() {
    static Date dd{2001, Month::jan, 1}; // start of 21st century
    return dd;
}

Date::Date():
y{default_date().year()},
m{default_date().month()},
d{default_date().day()} { }

void Date::add_day(int n) {
    //....
}

void Date::add_month(int n) {
    //../..
}

void Date::add_year(int n) {
    // beware of leap years
    if (m == Month::feb && d == 29 && leap_year(y + n)) {
        // use March 1 instead of February 29
        m = Month::mar;
        d = 1;
    }
    y += n;
}

// helper functions:
bool is_date(int y, Month m, int d) {
    // assume that y is valid
    if (d<=0) { // d must be positive (not 0, -1, -500 etc.)
        return false;
    }
    if (m<Month::jan || Month::dec<m) {
        return false;
    }
    int days_in_month = 31; // most months have 31 days
    switch (m) {
        //the length of February varies
        case Month::feb : {
            days_in_month = (leap_year(y)) ? 29 : 28;
            // '?' is an arithmetic 'if' meaning ==>
            // ==> if leap-year = TRUE
            // then days...=29
            // otherwise days...=28
            break;
        }
        case Month::apr:
        case Month::jun:
        case Month::sep:
        case Month::nov: {
            days_in_month = 30; // the rest have 31 days
            break;
        }
    }

    if (days_in_month < d) { // if d is too high (eg. 32, 500 etc.)
        return false;
    }
    return true; // finally return true
}

bool leap_year(int y) {
//    if (year is not divisible by 4) then (it is a common year)
    bool leap_year = false;
    if (y%4==0) {
        leap_year = true;
    }
//    else if (_year is not divisible by 100) then (it is a leap year)
    if (y%100==0) {
        leap_year = false;
    }
//    else if (_year is not divisible by 400) then (it is a common year)
    if (y%400==0) {
        leap_year = true;
    }
    return leap_year;
//    else (it is a leap year)
}

bool operator==(const Date& a, const Date& b) {
    bool res = {
            a.year() == b.year() &&
            a.month() == b.month() &&
            a.day() == b.day()
    };
    return res;
}

bool operator!=(const Date& a, const Date& b) {
    return !(a==b);
}

ostream& operator<<(ostream& os, const Date& d) {
    ostream& res = {
            os << '(' << d.year() << ',' << int(d.month()) << ',' << d.day() << ')'
    };
    return res;
}

istream& operator>>(istream& is, Date& dd) {
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    istream& res = {
            is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4
    };
    if (!is) {
        return is;
    }
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
        is.clear(ios_base::failbit); // set the fail bit
        return is;
    }
    dd = Date(y, Month(m), d); // update dd
    return is;
}

Day day_of_week(const Date& d) {
    ///
}

Date next_sunday(const Date& d) {
    ///
}

Date next_weekday(const Date& d) {
    ///
}

} // Chrono - End

void f(bool x) {
    if (x) {
        cout << "is Leap year\n";
    }
    else {
        cout << "not Leap year\n";
    }
}

int main() {
    f(Chrono::leap_year(2019));
}

