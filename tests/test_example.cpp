//
// Created by Jimmy on 12/22/24.
//
#include <gtest/gtest.h>

// A simple test case
TEST(SampleTest, Addition) {
    EXPECT_EQ(2 + 2, 4);
    EXPECT_EQ(3 + 3, 6);
}

// Another simple test case
TEST(SampleTest, Subtraction) {
    EXPECT_EQ(10 - 5, 5);
    EXPECT_EQ(8 - 3, 5);
}

// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
