#include "gtest/gtest.h"
#include "../chrono.h"
using namespace Chrono;


TEST(testingDate, test2) {
    // default constructor
    cout << "\nEXAMPLE DATE:\n";
    Date example = Date();
    // testing functions
    Chrono::operator<<(cout, example);
    // TODO later find how operator>> works!!!
    print_leap_year(example);

    example.add_day(3);
    example.add_month(3);
    example.add_year(3);
    Chrono::operator<<(cout, example);
    example.add_day(5);
    example.add_month(5);
    example.add_year(5);
    Chrono::operator<<(cout, example);
    example.add_day(30);
    Chrono::operator<<(cout, example);
    example.add_month(3);
    Chrono::operator<<(cout, example);
    cout << "NEXT WEEKDAY:\n";
    Date next_wd = next_weekday(example);
    Chrono::operator<<(cout, next_wd);
    // TODO WRITE FUNCTIONS FOR WEEK OF YEAR AND NEXT WORKDAY
}