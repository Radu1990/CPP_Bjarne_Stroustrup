#include "gtest/gtest.h"
#include "../Exercise_01.h"

TEST(testingCustom_io, f_1) {
    f_1("../../input.txt", "../../output.txt");
}

TEST(testingCustom_io, f_2) {
    f_2("../../input.txt", "sun");
}

TEST(testingCustom_io, f_3) {
    std::stringstream ss_1;

    ss_1 << "There are only two kinds of languages:"
            " languages that people complain about,"
            " and languages that people don't use";

    f_3(ss_1);

}

TEST(testingCustom_io, f_4) {
    // input: "0x43 0123 65"
    /*
     * output:
     * 0x43   	 hexadecimal   	 converts to   	67 decimal
     * 0123   	       octal   	 converts to   	83 decimal
     * 60   	     decimal   	 converts to   	60 decimal
     */
    istringstream aa {"0x43 0123 60"};
    f_4(aa);

    // input: "0x55 0135 150"
    /*
     * output:
     * 0x55   	 hexadecimal   	 converts to   	85 decimal
     * 0135   	       octal   	 converts to   	93 decimal
     * 150   	     decimal   	 converts to   	150 decimal
     */
    istringstream bb {"0x55 0135 150"};
    f_4(bb);


    // input: "0x78 0166 320"
    /*
     * output:
     * 0x78   	 hexadecimal   	 converts to   	120 decimal
     * 0166   	       octal   	 converts to   	118 decimal
     * 320   	     decimal   	 converts to   	320 decimal
     */
    istringstream cc {"0x78 0166 320"};
    f_4(cc);
}