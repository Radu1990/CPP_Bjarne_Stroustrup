#include "std_lib_facilities.h"

// Drill
// Date Version from 9.4.2
struct Date {
public:
    class Invalid{}; // exception to throw
    int y, m, d; // year month day
    Date(int y, int m, int d); // check for valid date and init
    void add_day(int n); // increase the Date by n days

};

bool is_date(int y, int m, int d) {
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
    if (y<1||2050<y) {
        return false;
    }
    if (m<1||12<m) {
        return false;
    }
    if (d<1||31<d) {
        return false;
    }
    // init dd
    return true;
}

Date::Date(int yy, int mm, int dd)
:y(yy), m(mm), d(dd) { if (!is_date(yy,mm,dd)) throw Invalid{}; }

void Date::add_day(int n) {
    d += n;
    if (!is_date(y,m,d)) throw Invalid{};
}



void f() {
    Date today {1978, 06, 25};
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << "today: " << today.y << "," << today.m << "," << today.d << endl;
    cout << "tomorrow: " << tomorrow.y << "," << tomorrow.m << "," << tomorrow.d << endl;
}

int main(){
    f();
}

