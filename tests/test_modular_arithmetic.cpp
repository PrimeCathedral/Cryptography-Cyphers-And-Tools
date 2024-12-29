//
// Created by Jimmy on 12/28/24.
//

#include <boost/multiprecision/detail/assert.hpp>
#include <gtest/gtest.h>
#include "../Utilities/ModularArithmetic.h"

TEST(TestModAdd, additionWorks) {
    const boost::multiprecision::cpp_int mod {10};
    ModularArithmetic ModularArithmetic(mod);
    EXPECT_LT(ModularArithmetic.add(5, 2), mod);
    EXPECT_EQ(ModularArithmetic.add(5, 2), 7);

    EXPECT_LT(ModularArithmetic.add(5, 10), mod);
}

TEST(TestModularArithmetic, BasicFunctionalTests) {

    // Test class does not build with division by zero
    ASSERT_THROW(ModularArithmetic(0), std::runtime_error);

    const boost::multiprecision::cpp_int mod {10};
    ModularArithmetic ModArithmetic(mod);

    EXPECT_LT(ModArithmetic.add(5, 2), mod); // a + b < mod
    EXPECT_LT(ModArithmetic.add(5, 5), mod); // a + b == mod
    EXPECT_LT(ModArithmetic.add(5, 12), mod); // a + b > mod

    EXPECT_EQ(ModArithmetic.add(5, 2), 7); // a + b < mod
    EXPECT_EQ(ModArithmetic.add(5, 5), 0); // a + b == mod
    EXPECT_EQ(ModArithmetic.add(5, 6), 1); // a + b > mod

    // Zero inputs
    EXPECT_EQ(ModArithmetic.add(0, 0), 0);
    EXPECT_EQ(ModArithmetic.add(0, 5), 5);
    EXPECT_EQ(ModArithmetic.add(5, 0), 5);

    // Modulo 1 should always return 0
    ModularArithmetic ModOne(1);
    EXPECT_EQ(ModOne.add(0,0), 0);
    EXPECT_EQ(ModOne.add(1,0), 0);
    EXPECT_EQ(ModOne.add(0,1), 0);
    EXPECT_EQ(ModOne.add(1,1), 0);

    // Negative numbers
    EXPECT_EQ(ModArithmetic.add(-2, 3), 1); // a > 0, b < 0
    EXPECT_EQ(ModArithmetic.add(7, -3), 4); // a < 0, b > 0
    EXPECT_EQ(ModArithmetic.add(-7, -3), 0); // a < 0, b <

    // Large numbers
    boost::multiprecision::cpp_int a("12345678901234567890123456789012345678901234567890");
    boost::multiprecision::cpp_int b("98765432109876543210987654321098765432109876543210");
    boost::multiprecision::cpp_int r("1111111011111111101111111110111111111011111111100");
    boost::multiprecision::cpp_int mod2("10000000000000000000000000000000000000000000000000");
    ModularArithmetic ModTwo(mod2);
    EXPECT_EQ(ModTwo.add(a, b), r);
}

// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}