//
// Created by Jimmy on 12/30/24.
//

#include <gtest/gtest.h>
#include "../Utilities/Primes.h"
#include "../Utilities/Utilities.h"

// Fermat Primality Test: Tests for identifying prime numbers
TEST(FermatPrimalityTest, IdentifiesPrimes) {
    // Small prime numbers
    EXPECT_EQ(Primes::FermatPrimalityTest(3, 10), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(5, 10), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(7, 10), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(11, 10), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(13, 10), true);

    // Large prime numbers
    EXPECT_EQ(Primes::FermatPrimalityTest(15485837, 3), true); // Prime near 15 million
    EXPECT_EQ(Primes::FermatPrimalityTest(15485843, 3), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(15485849, 3), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(15485857, 3), true);
    EXPECT_EQ(Primes::FermatPrimalityTest(15485863, 3), true);
}

// Fermat Primality Test: Tests for identifying composite numbers
TEST(FermatPrimalityTest, IdentifiesComposites) {
    // Small composite numbers
    EXPECT_EQ(Primes::FermatPrimalityTest(4, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(54, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(74, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(114, 10), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(134, 10), false);

    // Large composite numbers
    EXPECT_EQ(Primes::FermatPrimalityTest(154858372, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858432, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858492, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858572, 3), false);
    EXPECT_EQ(Primes::FermatPrimalityTest(154858632, 3), false);
}

// Fermat Primality Test: Tests for Mersenne primes: https://t5k.org/mersenne/index.html#known
TEST(FermatPrimalityTest, AcceptsMersennePrimes) {
    // Mersenne prime 2^127 - 1
    cpp_int m{"170141183460469231731687303715884105727"};
    EXPECT_EQ(Primes::FermatPrimalityTest(m, 10), true);

    // Very large Mersenne prime (may take longer to test)
    cpp_int mersenne {Utilities::binaryExponentiation(2, 1279) - 1};
    EXPECT_EQ(Primes::FermatPrimalityTest(mersenne, 1), true);
}

// Fermat Primality Test: Tests for Carmichael numbers
TEST(FermatPrimalityTest, RejectCarmichaelNumbers) {
    // 561 is a Carmichael number
    EXPECT_EQ(Primes::FermatPrimalityTest(561, 10), false);
}

// Miller-Rabin Primality Test: Tests for identifying prime numbers
TEST(MillerRabinPrimalityTest, IdentifiesPrimes) {
    // Small prime numbers
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(5, 10), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(7, 10), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(11, 10), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(13, 10), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(17, 10), true);

    // Large prime numbers
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485837, 3), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485843, 3), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485849, 3), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485857, 3), true);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(15485863, 3), true);
}

// Miller-Rabin Primality Test: Tests for Mersenne primes
TEST(MillerRabinPrimalityTest, AcceptsMersennePrimes) {
    // Mersenne prime 2^127 - 1
    cpp_int m{"170141183460469231731687303715884105727"};
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(m, 10), true);

    // Very large Mersenne prime (may take longer to test)
    cpp_int mersenne {Utilities::binaryExponentiation(2, 1279) - 1};
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(mersenne, 1), true);
}


// Miller-Rabin Primality Test: Tests for identifying composite numbers
TEST(MillerRabinPrimalityTest, IdentifiesComposites) {
    // Small composite numbers
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(4, 10), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(54, 10), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(74, 10), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(114, 10), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(134, 10), false);

    // Large composite numbers
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(154858372, 3), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(154858432, 3), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(154858492, 3), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(154858572, 3), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(154858632, 3), false);
}

// Miller-Rabin Primality Test: Tests for Carmichael numbers
TEST(MillerRabinPrimalityTest, RejectCarmichaelNumbers) {
    // 561 is a Carmichael number
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(561, 10), false);

    // Additional Carmichael numbers
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(1105, 10), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(1729, 10), false);
    EXPECT_EQ(Primes::MillerRabinPrimalityTest(2465, 10), false);
}

// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
