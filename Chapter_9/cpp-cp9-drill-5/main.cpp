#include "std_lib_facilities.h"

// Drill
// Date Version from 9.7.4
enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
//----------------------------------------------------------------------------
class Year {
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid{}; // exception to throw
    explicit Year(int x)
            :y{x} { if (x < min || max < x) throw Invalid{}; } // Year constructor
    int year() const {
        return y;
    }
private:
    int y; // class type member
};
//----------------------------------------------------------------------------
class Date {
public:
    class Invalid{}; // exception to throw

    Date(Year y, Month m, int d); // check for valid date and init

    // can't modify the object:
    int year() const {
        return y.year();
    }

    int month() const {
        return int(m);
    }
    int day() const {
        return d;
    }
    // can modify the object:
    void add_day(int n); // increase the Date by n days
    void add_month(int n);
    void add_year(int n);

private:
    Year y;
    Month m;
    int d;
};
//----------------------------------------------------------------------------
bool is_date(Year y, Month m, int d) {
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
    if (y.year() < 1 || 2050 < y.year()) {
        return false;
    }
    if (int(m) < 1 || 12 < int(m)) {
        return false;
    }
    if (d < 1 || 31 < d) {
        return false;
    }
    // init dd
    return true;
}

Date::Date(Year yy, Month mm, int dd)
        :y(yy), m(mm), d(dd) { if (!is_date(yy,mm,dd)) throw Invalid{}; }

void Date::add_day(int n) {
    d += n;
    if (!is_date(y,m,d)) throw Invalid{};
}

void Date::add_month(int n) {
    int new_month = month() + n; // [(get month as int) + n]
    m = Month(new_month); // assign new month to our Date's month
    if (!is_date(y,m,d)) throw Invalid{}; // check if everything's ok :)
}

void Date::add_year(int n) {
    int new_year = y.year() + n;
    Year x {new_year};
    y = x;
    if (!is_date(y,m,d)) throw Invalid{};
}
void f() {
    Date today {Year{1978}, Month(6), 25};
    Date tomorrow = today;
    tomorrow.add_day(1);
    tomorrow.add_month(1);
    tomorrow.add_year(1);
    // y, m, d can be accessed only through these functions now because we made them private
    cout << "today: " << today.year() << "," << today.month() << "," << today.day() << endl;
    cout << "tomorrow: " << tomorrow.year() << "," << tomorrow.month() << "," << tomorrow.day() << endl;
}

int main(){
    f();
}
