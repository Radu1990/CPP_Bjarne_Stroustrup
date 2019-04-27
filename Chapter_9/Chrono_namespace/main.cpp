#include "std_lib_facilities.h"

class Year {
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid{};
    explicit Year(int x) : y{x} {if (x < min || max <= x) throw Invalid{};}
    int year() { return y; }
private:
    int y;
};

enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
    class Invalid{}; // to be used as exception
    Date(Year yy, Month mm, int dd); // check for valid Date and initialize
    Date();

private:
    Year y;
    Month m;
    int d; // day
};
Date::Date(): y{2001}, m{Month::jan}, d{1} { }
Date::Date(Year yy, Month mm, int dd): y{yy}, m{mm}, d{dd} { } // initialize data members

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}



