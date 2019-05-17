#include "gtest/gtest.h"
#include "../custom_io.h"

TEST(testingCustom_io, test1) {
    f_1();
}

TEST(testingCustom_io, test2) {
    f_2();
}
TEST(testingCustom_io, test3) {
    f_3();
}
TEST(testingCustom_io, test4) {
    f_4();
}
TEST(testingCustom_io, test5) {
    f_5();
}
TEST(testingCustom_io, test6) {
    // Input 1: 1234 4d2 2322 2322
    std::stringstream ss_1;
    ss_1 << "1234 4d2 2322 2322";
    // Input 2: 1234 0x4d2 02322 02322
    std::stringstream ss_2;
    ss_2 << "1234 0x4d2 02322 02322";

    f_6(ss_1, ss_2);

    // Output 1: 1234 1234 1234 1234
    // Output 2: 1234 1234 1234 1234


}

TEST(testingCustom_io, test6_1) {

    f_6_1();

    // Output 1: 1234 1234 1234 1234
    // Output 2: 1234 1234 1234 1234


}

TEST(testingCustom_io, test7) {
    f_7();
}
TEST(testingCustom_io, test_try_this_1) {
    try_this_1();
}
TEST(testingCustom_io, test8) {
    f_8();
}
TEST(testingCustom_io, test9) {
    f_9();
}

TEST(testingCustom_io, test_try_this_2) {
    try_this_2();
}
