#include "gtest/gtest.h"
#include "../drill.h"

TEST(testingCustom_io, f_1) {
    f_1();
}

TEST(testingCustom_io, f_2) {
    f_2();
}

TEST(testingCustom_io, f_3) {
    // Input: 1234567.89
    f_3();
    // Output: 1.23457e+06	1234567.890000	1.234568e+06
    // Most accurate is the fixed form
    // all representations use 6 digits precision because
    // of default float.
}
