//
// Created by cho on 04.05.19.
//

#include "gtest/gtest.h"
#include "../Example.h"

TEST(FirstTest, simple) {
    EXPECT_TRUE(false);
    EXPECT_TRUE(false);
    EXPECT_TRUE(false);
}

TEST(FirstTest, firstfunction) {
//    int a = func_sum(1,1);
    EXPECT_EQ(2, func_sum(1,1));
}