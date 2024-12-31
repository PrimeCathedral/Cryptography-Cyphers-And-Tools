//
// Created by Jimmy on 12/30/24.
//


#include <gtest/gtest.h>
#include "../Utilities/Primes.h"
#include "../Utilities/Utilities.h"

TEST(FermatPrimalityTest, IdentifiesPrimes) {
    EXPECT_EQ(Primes::FermatPrimalityTest(3, 10), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(5, 10), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(7, 10), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(11, 10), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(13, 10), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(15485837, 3), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(15485843, 3), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(15485849, 3), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(15485857, 3), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(15485863, 3), true);
}

TEST(FermatPrimalityTest, IdentifiesComposites) {
    EXPECT_EQ(Primes::FermatPrimalityTest(4, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(54, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(74, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(114, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(134, 10), false);

    EXPECT_EQ(Primes::FermatPrimalityTest(154858372, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858432, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858492, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858572, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858632, 3), false);
}

TEST(FermatPrimalityTest, AcceptsMersennePrimes) {
    cpp_int m{"170141183460469231731687303715884105727"};
    EXPECT_EQ(Primes::FermatPrimalityTest(m, 10), true);
    cpp_int mersenne {Utilities::binaryExponentiation(2, 136279841) - 1};
    // EXPECT_EQ(Primes::FermatPrimalityTest(mersenne, 50), true);
}

TEST(FermatPrimalityTest, RejectCarmichaelNumbers) {
    EXPECT_EQ(Primes::FermatPrimalityTest(561, 10), false);
}

TEST(MillerRabinPrimalityTest, IdentifiesPrimes) {
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(5, 10), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(7, 10), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(11, 10), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(13, 10), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(17, 10), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485837, 3), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485843, 3), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485849, 3), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485857, 3), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485863, 3), true);
}

TEST(MillerRabinPrimalityTest, IdentifiesComposites) {
    EXPECT_EQ(Primes::FermatPrimalityTest(4, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(54, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(74, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(114, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(134, 10), false);

    EXPECT_EQ(Primes::FermatPrimalityTest(154858372, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858432, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858492, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858572, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858632, 3), false);
}


// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}