#include "chrono.h"

namespace Chrono {
// member functions definitions
Date::Date(int yy, Month mm, int dd, Day ww): // Date constructor
    y{yy}, m{mm}, d{dd}, w{ww} {
    if (!is_date(yy, mm, dd)) throw MyException();
}

const Date& default_date() { // constant Date used by default constructor
    static Date dd{2001, Month::jan, 1, Day::sunday}; // start of 21st century
    return dd;
}

Date::Date(): // default constructor
y{default_date().year()}, m{default_date().month()}, d{default_date().day()}, w{default_date().weekday()} { }

void Date::add_day(int n) {
    d += n;
    if (d>31) {
        d -= 31;
        add_month(1);
    }
}

void Date::add_month(int n) {
    int new_month;
    new_month = int(m) + n;
    if (new_month > 12) {
        m = Month(new_month-12);
    }
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
    if (int(m) < int(Month::jan) || int(Month::dec) < int(m)) {
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

    return (days_in_month >= d); // if d is too high (eg. 32, 500 etc.)
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

void print_leap_year(int x) {
    bool year = leap_year(x);
    if (year) {
        cout << "\n" << x << " is a Leap year";
    }
    else {
        cout << "\n" << x << " is not a Leap year";
    }
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

ostream& operator << (ostream& os, const Date& d) {
    ostream& res = {
            os << '(' << d.year() << ',' << int(d.month()) << ',' << d.day() << "," <<  int(d.weekday()) << ')'
    };
    return res;
}

istream& operator >> (istream& is, Date& dd) {
    int y, m, d, w;
    char ch1, ch2, ch3, ch4, ch5;

    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4 >> w >> ch5;

    if (!is) {
        return is;
    }
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ',' || ch5 != ')') { // oops: format error
        is.clear(ios_base::failbit); // set the fail bit
        return is;
    }
    dd = Date(y, Month(m), d, Day(w)); // update dd

    return is;
}

Date next_sunday(const Date& dd) {

    // fetching current date members
    int d_curr = dd.day();
    Month m_curr = dd.month();
    int y_curr = dd.year();
    Day wd_curr = dd.weekday();

    // next Sunday members
    int d_next{};
    Month m_next{};
    int y_next{};
    Day wd_next{Day::sunday};

    // checking for next Sunday
    // Switch - Begin
    switch (wd_curr) {
        case Day::sunday : {
            d_next = d_curr + 7;
            break;
            }
        case Day::monday : {
            d_next = d_curr + 6;
            break;
        }
        case Day::tuesday : {
            d_next = d_curr + 5;
            break;
        }
        case Day::wednesday : {
            d_next = d_curr + 4;
            break;
        }
        case Day::thursday : {
            d_next = d_curr + 3;
            break;
        }
        case Day::friday : {
            d_next = d_curr + 2;
            break;
        }
        case Day::saturday : {
            d_next = d_curr + 1;
            break;
        }
        default: {}
    }
    // Switch - End

    // writing new date in case month (and year) changes
    if (d_next>31) {

        d_next = d_next - 31;

        if (m_curr == Month::dec) {
            m_next = Month::jan;
            y_next = y_curr + 1;
        }
        else {
            m_next = Month(int(m_curr)+1);
            y_next = y_curr;
        }

    }
    // in case month (and year) stays the same
    else {
        m_next = m_curr;
        y_next = y_curr;
    }
    Date ret = Date(y_next, m_next, d_next, wd_next);
    return ret;
}

Date week_day(const Date& dd) {

    // fetching current date members
    int d_curr = dd.day();
    Month m_curr = dd.month();
    int y_curr = dd.year();
    Day wd_curr = dd.weekday();

    // next Sunday members
    int d_next{};
    Month m_next{};
    int y_next{};
    Day wd_next{};

    // checking for next Sunday
    // Switch - Begin
    switch (wd_curr) {
        case Day::sunday : {
            wd_next = Day::monday;
            break;
        }
        case Day::monday : {
            wd_next = Day::tuesday;
            break;
        }
        case Day::tuesday : {
            wd_next = Day::wednesday;
            break;
        }
        case Day::wednesday : {
            wd_next = Day::thursday;
            break;
        }
        case Day::thursday : {
            wd_next = Day::friday;
            break;
        }
        case Day::friday : {
            wd_next = Day::saturday;
            break;
        }
        case Day::saturday : {
            wd_next = Day::sunday;
            break;
        }
        default: {}
    }
    // Switch - End

    d_next = d_curr + 1;

    // writing new date in case month (and year) changes
    if (d_next>31) {

        d_next = d_next - 31;

        if (m_curr == Month::dec) {
            m_next = Month::jan;
            y_next = y_curr + 1;
        }
        else {
            m_next = Month(int(m_curr)+1);
            y_next = y_curr;
        }

    }
        // in case month (and year) stays the same
    else {
        m_next = m_curr;
        y_next = y_curr;
    }
    Date ret = Date(y_next, m_next, d_next, wd_next);
    return ret;
}

} // Chrono - End

