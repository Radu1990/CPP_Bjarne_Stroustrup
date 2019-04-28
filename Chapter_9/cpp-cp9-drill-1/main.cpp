#include "std_lib_facilities.h"

// Drill
// Date Version from 9.4.1

struct Date {
public:
    int y;
    int m;
    int d;
};

// helper functions:
void init_day(Date& dd, int y, int m, int d) {
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
    if (y<1||2050<y) {
        error("Year must be in range 1-2050!");
    }
    if (m<1||12<m) {
        error("Month must be in range 1-12!");
    }
    if (d<1||31<d) {
        error("Day must be in range 1-31!");
    }
    // init dd
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n) {
    dd.d += n;
}

void f() {
    Date today {0,0,0};
    init_day(today, 1978, 06, 25);

    Date tomorrow = today;
    add_day(tomorrow, 1);
    init_day(tomorrow, tomorrow.y, tomorrow.m, tomorrow.d);

    cout << "today: " << today.y << "," << today.m << "," << today.d << endl;
    cout << "tomorrow: " << tomorrow.y << "," << tomorrow.m << "," << tomorrow.d << endl;
}

int main(){
    f();
}

