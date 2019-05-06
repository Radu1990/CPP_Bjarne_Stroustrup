#include "gtest/gtest.h"
#include "../chrono.h"
using namespace Chrono;

TEST(testingBookClass, test1) {
    Chrono::print_leap_year(2004);
    Chrono::print_leap_year(2005);
}

TEST(testingDate, test2) {
    // default constructor
    Date example = Date();

    Chrono::operator<<(cout, example);
    // TODO later find how operator>> works!!!

}