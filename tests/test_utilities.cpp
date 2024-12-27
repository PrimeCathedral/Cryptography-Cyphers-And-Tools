//
// Created by Jimmy on 12/22/24.
//
#include <gtest/gtest.h>
#include "../Utilities.h"

//TEST(TestSuiteName, testName) {
//
//}

TEST(TestUtilities, SimpleFermatIdentifiesPrimes) {
    using namespace Crypto;

    EXPECT_EQ(true, Utilities::FermatPrimalityTest(3, 2));

    EXPECT_EQ(false, Utilities::FermatPrimalityTest(4, 2));

    EXPECT_EQ(true, Utilities::FermatPrimalityTest(5, 2));

    EXPECT_EQ(true, Utilities::FermatPrimalityTest(1223, 2));

    EXPECT_EQ(false, Utilities::FermatPrimalityTest(3727, 2));

    EXPECT_EQ(false, Utilities::FermatPrimalityTest(10000, 2));

    // Mersenne prime, should be true
    EXPECT_EQ(true, Utilities::FermatPrimalityTest(2305843009213693951, 2));

    // This next one is a Fermat's Liar, it should return true even though it is not a prime.
    EXPECT_EQ(true, Utilities::FermatPrimalityTest(561, 8));
}

// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}