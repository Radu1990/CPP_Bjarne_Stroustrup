#include "gtest/gtest.h"
#include "../nonstandard_op.h"

TEST(testingCustom_io, f_main) {
    // Input: "There are only two kinds of languages: languages that people complain about,
    // and languages that people don't use";
    std::stringstream ss_1;
    ss_1 << "There are only two kinds of languages:"
            " languages that people complain about,"
            " and languages that people don't use";

    f_main(ss_1);

    /* Output:
    about
    and
    are
    complain
    don't
    kinds
    languages
    of
    only
    people
    that
    there
    two
    */

}
