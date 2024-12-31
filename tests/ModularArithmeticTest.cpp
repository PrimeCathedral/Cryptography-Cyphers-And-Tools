//
// Created by Jimmy on 12/22/24.
//
#include <gtest/gtest.h>
#include "../Utilities/ModularArithmetic.h"

TEST(TestModularExponentiation, PowersOfTwo) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Power of 2
    ASSERT_EQ(ModularArithmetic.modularExponentiation(2, 10, 1024), 0);
}

TEST(TestModularExponentiation, ZeroToTheZero) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // 0^0
    ASSERT_THROW(ModularArithmetic.modularExponentiation(0,0,2), std::runtime_error);
}

TEST(TestModularExponentiation, PowerIsZero) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // a^0
    ASSERT_EQ(ModularArithmetic.modularExponentiation(2,0,2), 1);
}

TEST(TestModularExponentiation, BaseIsZero) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // 0^a
    ASSERT_EQ(ModularArithmetic.modularExponentiation(0,2,2), 0);
}

TEST(TestModularExponentiation, BaseGreaterThanModulus) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Base > Mod
    ASSERT_EQ(ModularArithmetic.modularExponentiation(17,3,5), 3);
}

TEST(TestModularExponentiation, PowerGreaterThanModulus) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Power > Mod
    ASSERT_EQ(ModularArithmetic.modularExponentiation(3,12,7), 1);
}

TEST(TestModularExponentiation, LE20Digit) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Large numbers
    cpp_int base {"123456789012345678901234567890123456789"};
    cpp_int power {"98765432109876543210987654321"};
    cpp_int modulus {"1000000007"};
    cpp_int result {"837711231"};
    ASSERT_EQ(ModularArithmetic.modularExponentiation(base, power, modulus), result);

    // TODO add more cases here. Test the limits on digit length

}

TEST(TestModularExponentiation, ModulusIsOne) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Small modulus (anything modulo 1 is 0)
    ASSERT_EQ(ModularArithmetic.modularExponentiation(5, 10, 1), 0);
}

TEST(TestModularExponentiation, PowerIsOne) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Power = 1
    ASSERT_EQ(ModularArithmetic.modularExponentiation(45, 1, 7), 45 % 7);
}

// Modular inverse: https://www.dcode.fr/modular-inverse

TEST(TestModularMultiplicativeInverse, ModularInverseExists) {
    Crypto::ModularArithmetic ModularArithmetic{};
    EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(3, 7), 5);
}

TEST(TestModularMultiplicativeInverse, ModularInverseDoesNotExist) {
    Crypto::ModularArithmetic ModularArithmetic{};
    EXPECT_THROW(ModularArithmetic.modularMultiplicativeInverse(4, 8), std::runtime_error);
}

TEST(TestModularMultiplicativeInverse, LE20Digit) {
    Crypto::ModularArithmetic ModularArithmetic{};
    cpp_int a {cpp_int("12345678901234567890")};
    cpp_int mod {cpp_int("98765432109876543211")};
    EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(a, mod), cpp_int("94316753668893093070")); // Precomputed result
}

TEST(TestModularMultiplicativeInverse, NegativeBase) {
    Crypto::ModularArithmetic ModularArithmetic{};

    EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(-5, 7), 3);
    // TODO add better testcases. Code handles this by swapping symbols
}

TEST(TestModularMultiplicativeInverse, BaseIsOne) {
    Crypto::ModularArithmetic ModularArithmetic{};

    EXPECT_EQ(ModularArithmetic.modularMultiplicativeInverse(1, 13), 1);
}

TEST(TestModularMultiplicativeInverse, ModulusIsOne) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // Modular inverse does not exist when the modulus is 1
    EXPECT_THROW(ModularArithmetic.modularMultiplicativeInverse(5, 1), std::runtime_error);
}

TEST(TestModularMultiplicativeInverse, NotCoprime) {
    Crypto::ModularArithmetic ModularArithmetic{};

    // GCD is not 1
    EXPECT_THROW(ModularArithmetic.modularMultiplicativeInverse(12, 15), std::runtime_error);
}

// Extended Euclidean Algorithm: https://www.dcode.fr/gcd


TEST(TestExtendedGCD, BaseCase) {
    cpp_int x, y;
    cpp_int base = 10, modulus = 0;
    cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 10);  // GCD should be 10
    EXPECT_EQ(x, 1);     // x should be 1
    EXPECT_EQ(y, 0);     // y should be 0
}

TEST(TestExtendedGCD, CoprimeNumbers) {
    cpp_int x, y;
    cpp_int base = 17, modulus = 13;
    cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 1);
    EXPECT_EQ(17 * x + 13 * y, gcd);
}

TEST(TestExtendedGCD, NonCoprimeNumbers) {
    cpp_int x, y;
    cpp_int base = 12, modulus = 8;
    cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 4);
    EXPECT_EQ(12 * x + 8 * y, gcd);
}

TEST(TestExtendedGCD, NegativeBase) {
    cpp_int x, y;
    cpp_int base = -3, modulus = 7;
    cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 1);
    EXPECT_EQ(-3 * x + 7 * y, gcd);
}

TEST(TestExtendedGCD, LE20Digit) {

    cpp_int x, y;
    cpp_int base    {"12345678901234567890"};
    cpp_int modulus {"9876543210987654321"};
    cpp_int gcd = Crypto::ModularArithmetic::extendedGCD(base, modulus, x, y);

    EXPECT_EQ(gcd, 90000000009);
    EXPECT_EQ(base * x + modulus * y, gcd); // Verify the linear combination
}

// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}