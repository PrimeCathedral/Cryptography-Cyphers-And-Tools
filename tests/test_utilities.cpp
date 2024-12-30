//
// Created by Jimmy on 12/22/24.
//
#include <gtest/gtest.h>
#include "../Utilities.h"

//TEST(TestSuiteName, testName) {
//
//}

// TEST(TestUtilities, SimpleFermatIdentifiesPrimes) {
//     using namespace Crypto;
//
//     EXPECT_EQ(true, Utilities::FermatPrimalityTest(3, 2));
//
//     EXPECT_EQ(false, Utilities::FermatPrimalityTest(4, 2));
//
//     EXPECT_EQ(true, Utilities::FermatPrimalityTest(5, 2));
//
//     EXPECT_EQ(true, Utilities::FermatPrimalityTest(1223, 2));
//
//     EXPECT_EQ(false, Utilities::FermatPrimalityTest(3727, 2));
//
//     EXPECT_EQ(false, Utilities::FermatPrimalityTest(10000, 2));
//
//     // Mersenne prime, should be true
//     EXPECT_EQ(true, Utilities::FermatPrimalityTest(2305843009213693951, 2));
//
//     // This next one is a Fermat's Liar, it should return true even though it is not a prime.
//     EXPECT_EQ(true, Utilities::FermatPrimalityTest(561, 8));
// }

TEST(TestModularExponentiation, PowersOfTwo) {
    Crypto::Utilities Utilities{};

    // Power of 2
    ASSERT_EQ(Utilities.modularExponentiation(2, 10, 1024), 0);
}

TEST(TestModularExponentiation, ZeroToTheZero) {
    Crypto::Utilities Utilities{};

    // 0^0
    ASSERT_THROW(Utilities.modularExponentiation(0,0,2), std::runtime_error);
}

TEST(TestModularExponentiation, PowerIsZero) {
    Crypto::Utilities Utilities{};

    // a^0
    ASSERT_EQ(Utilities.modularExponentiation(2,0,2), 1);
}

TEST(TestModularExponentiation, BaseIsZero) {
    Crypto::Utilities Utilities{};

    // 0^a
    ASSERT_EQ(Utilities.modularExponentiation(0,2,2), 0);
}

TEST(TestModularExponentiation, BaseGreaterThanModulus) {
    Crypto::Utilities Utilities{};

    // Base > Mod
    ASSERT_EQ(Utilities.modularExponentiation(17,3,5), 3);
}

TEST(TestModularExponentiation, PowerGreaterThanModulus) {
    Crypto::Utilities Utilities{};

    // Power > Mod
    ASSERT_EQ(Utilities.modularExponentiation(3,12,7), 1);
}

TEST(TestModularExponentiation, LE20Digit) {
    Crypto::Utilities Utilities{};

    // Large numbers
    boost::multiprecision::cpp_int base {"123456789012345678901234567890123456789"};
    boost::multiprecision::cpp_int power {"98765432109876543210987654321"};
    boost::multiprecision::cpp_int modulus {"1000000007"};
    boost::multiprecision::cpp_int result {"837711231"};
    ASSERT_EQ(Utilities.modularExponentiation(base, power, modulus), result);

    // TODO add more cases here. Test the limits on digit length

}

TEST(TestModularExponentiation, ModulusIsOne) {
    Crypto::Utilities Utilities{};

    // Small modulus (anything modulo 1 is 0)
    ASSERT_EQ(Utilities.modularExponentiation(5, 10, 1), 0);
}

TEST(TestModularExponentiation, PowerIsOne) {
    Crypto::Utilities Utilities{};

    // Power = 1
    ASSERT_EQ(Utilities.modularExponentiation(45, 1, 7), 45 % 7);
}

// Modular inverse: https://www.dcode.fr/modular-inverse

TEST(TestModularInverse, ModularInverseExists) {
    Crypto::Utilities Utilities{};
    EXPECT_EQ(Utilities.modularInverse(3, 7), 5);
}

TEST(TestModularInverse, ModularInverseDoesNotExist) {
    Crypto::Utilities Utilities{};
    EXPECT_THROW(Utilities.modularInverse(4, 8), std::runtime_error);
}

TEST(TestModularInverse, LE20Digit) {
    Crypto::Utilities Utilities{};
    mp::cpp_int a {boost::multiprecision::cpp_int("12345678901234567890")};
    mp::cpp_int mod {boost::multiprecision::cpp_int("98765432109876543211")};
    EXPECT_EQ(Utilities.modularInverse(a, mod), boost::multiprecision::cpp_int("94316753668893093070")); // Precomputed result
}

TEST(TestModularInverse, NegativeBase) {
    Crypto::Utilities Utilities{};

    EXPECT_EQ(Utilities.modularInverse(-5, 7), 3);
    // TODO add better testcases. Code handles this by swapping symbols
}

TEST(TestModularInverse, BaseIsOne) {
    Crypto::Utilities Utilities{};

    EXPECT_EQ(Utilities.modularInverse(1, 13), 1);
}

TEST(TestModularInverse, ModulusIsOne) {
    Crypto::Utilities Utilities{};

    // Modular inverse does not exist when the modulus is 1
    EXPECT_THROW(Utilities.modularInverse(5, 1), std::runtime_error);
}

TEST(TestModularInverse, NotCoprime) {
    Crypto::Utilities Utilities{};

    // GCD is not 1
    EXPECT_THROW(Utilities.modularInverse(12, 15), std::runtime_error);
}

// Extended Euclidean Algorithm: https://www.dcode.fr/gcd


TEST(ExtendedGCD, BaseCase) {
    Crypto::Utilities Utilities;

    mp::cpp_int x, y;
    mp::cpp_int base = 10, modulus = 0;
    mp::cpp_int gcd = Utilities.extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 10);  // GCD should be 10
    EXPECT_EQ(x, 1);     // x should be 1
    EXPECT_EQ(y, 0);     // y should be 0
}

TEST(ExtendedGCD, CoprimeNumbers) {
    Crypto::Utilities Utilities;

    mp::cpp_int x, y;
    mp::cpp_int base = 17, modulus = 13;
    mp::cpp_int gcd = Utilities.extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 1);
    EXPECT_EQ(17 * x + 13 * y, gcd);
}

TEST(ExtendedGCD, NonCoprimeNumbers) {
    Crypto::Utilities Utilities;

    mp::cpp_int x, y;
    mp::cpp_int base = 12, modulus = 8;
    mp::cpp_int gcd = Utilities.extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 4);
    EXPECT_EQ(12 * x + 8 * y, gcd);
}

TEST(ExtendedGCD, NegativeBase) {
    Crypto::Utilities Utilities;

    mp::cpp_int x, y;
    mp::cpp_int base = -3, modulus = 7;
    mp::cpp_int gcd = Utilities.extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 1);
    EXPECT_EQ(-3 * x + 7 * y, gcd);
}

TEST(ExtendedGCD, LE20Digit) {
    Crypto::Utilities Utilities;

    mp::cpp_int x, y;
    mp::cpp_int base    {"12345678901234567890"};
    mp::cpp_int modulus {"9876543210987654321"};
    mp::cpp_int gcd = Utilities.extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 90000000009);
    EXPECT_EQ(base * x + modulus * y, gcd); // Verify the linear combination
}

// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}