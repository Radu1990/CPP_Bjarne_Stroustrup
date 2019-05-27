#include "gtest/gtest.h"
#include "../Exercise_01.h"

TEST(testingCustom_io, f_1) {
    f_1("../../input.txt", "../../output.txt");
}

TEST(testingCustom_io, f_2) {
    f_2("../../input.txt", "sun");
}
