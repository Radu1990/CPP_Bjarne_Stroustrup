using namespace std;

#include "string"
#include "vector"
#include "iostream"
#include "exception"
#include "bitset"

#ifndef CHRONO_H
#define CHRONO_H

namespace Chrono {

struct MyException : std::exception
{
    const char* what() const noexcept override { return "Buggers!"; }
};

enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class Day{
    sunday=1, monday, tuesday, wednesday, thursday, friday, saturday
};

class Date{
public:

    Date(int yy, Month mm, int dd, Day ww); // check for valid date and initialize
    Date(); // default constructor
    // the default copy operations are fine

    // non-modifying operations:
    int day() const {
        return d;
    }
    Month month() const {
        return m;
    }
    int year() const {
        return y;
    }
    Day weekday() const {
        return w;
    }

    // modifying operations:
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

private:
    int y;
    Month m;
    int d;
    Day w; // day of week
};

bool is_date(int y, Month m, int d); // true for valid date
bool leap_year (int y); // true if y is a leap year
void print_leap_year(int x);

bool operator==(const Date& x, const Date& y);
bool operator!=(const Date& x, const Date& y);
ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, const Date& dd);

Date next_sunday(const Date& dd);
Date next_weekday(const Date& d); // next weekday after d
Date next_workday(const Date& d); // next workday after d
Date week_of_year(const Date& d);

}

#endif //CHRONO_H