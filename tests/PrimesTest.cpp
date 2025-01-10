//
// Created by Jimmy on 12/30/24.
//

#include "../Utilities/Primes.hpp"
#include "../Utilities/Utilities.hpp"
#include <gtest/gtest.h>

using cpp_int = boost::multiprecision::cpp_int;

// Fermat Primality Test: Tests for identifying prime numbers
TEST(FermatPrimalityTest, IdentifiesPrimes) {
  // Small prime numbers
  EXPECT_TRUE(Primes::FermatPrimalityTest(3));
  EXPECT_TRUE(Primes::FermatPrimalityTest(5));
  EXPECT_TRUE(Primes::FermatPrimalityTest(7));
  EXPECT_TRUE(Primes::FermatPrimalityTest(11));
  EXPECT_TRUE(Primes::FermatPrimalityTest(13));
  EXPECT_TRUE(Primes::FermatPrimalityTest(15485837)); // Prime near 15 million
  EXPECT_TRUE(Primes::FermatPrimalityTest(15485843));
  EXPECT_TRUE(Primes::FermatPrimalityTest(15485849));
  EXPECT_TRUE(Primes::FermatPrimalityTest(15485857));
  EXPECT_TRUE(Primes::FermatPrimalityTest(15485863));
}

// Fermat Primality Test: Tests for identifying composite numbers
TEST(FermatPrimalityTest, IdentifiesComposites) {
  // Small composite numbers
  EXPECT_FALSE(Primes::FermatPrimalityTest(4));
  EXPECT_FALSE(Primes::FermatPrimalityTest(54));
  EXPECT_FALSE(Primes::FermatPrimalityTest(74));
  EXPECT_FALSE(Primes::FermatPrimalityTest(114));
  EXPECT_FALSE(Primes::FermatPrimalityTest(134));
  EXPECT_FALSE(Primes::FermatPrimalityTest(154858372));
  EXPECT_FALSE(Primes::FermatPrimalityTest(154858432));
  EXPECT_FALSE(Primes::FermatPrimalityTest(154858492));
  EXPECT_FALSE(Primes::FermatPrimalityTest(154858572));
  EXPECT_FALSE(Primes::FermatPrimalityTest(154858632));
}

// Fermat Primality Test: Tests for Mersenne primes:
// https://t5k.org/mersenne/index.html#known
TEST(FermatPrimalityTest, AcceptsMersennePrimes) {
  // Mersenne prime 2^127 - 1
  cpp_int mersenne1{"170141183460469231731687303715884105727"};
  EXPECT_TRUE(Primes::FermatPrimalityTest(mersenne1));

  // Very large Mersenne prime (may take longer to test)
  cpp_int mersenne2{Utilities::binaryExponentiation(2, 1279) - 1};
  EXPECT_TRUE(Primes::FermatPrimalityTest(mersenne2));
}

// Fermat Primality Test: Tests for Carmichael numbers
TEST(FermatPrimalityTest, RejectCarmichaelNumbers) {
  EXPECT_FALSE(Primes::FermatPrimalityTest(561));
  EXPECT_FALSE(Primes::FermatPrimalityTest(1105));
  EXPECT_FALSE(Primes::FermatPrimalityTest(1729));
  EXPECT_FALSE(Primes::FermatPrimalityTest(2465));
}

// Miller-Rabin Primality Test: Tests for identifying prime numbers
TEST(MillerRabinPrimalityTest, IdentifiesPrimes) {
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(5));
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(7));
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(11));
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(13));
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(17));
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(15485837));
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(15485843));
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(15485849));
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(15485857));
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(15485863));
}

// Miller-Rabin Primality Test: Tests for Mersenne primes
TEST(MillerRabinPrimalityTest, AcceptsMersennePrimes) {
  // Mersenne prime 2^127 - 1
  cpp_int mersenne1{"170141183460469231731687303715884105727"};
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(mersenne1));

  // Very large Mersenne prime (may take longer to test)
  cpp_int mersenne2{Utilities::binaryExponentiation(2, 1279) - 1};
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(mersenne2));
}

// Miller-Rabin Primality Test: Tests for identifying composite numbers
TEST(MillerRabinPrimalityTest, IdentifiesComposites) {
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(4));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(54));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(74));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(114));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(134));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(154858372));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(154858432));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(154858492));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(154858572));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(154858632));
}

// Miller-Rabin Primality Test: Tests for Carmichael numbers
TEST(MillerRabinPrimalityTest, RejectCarmichaelNumbers) {
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(561));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(1105));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(1729));
  EXPECT_FALSE(Primes::MillerRabinPrimalityTest(2465));
}

TEST(GeneratePrimesTest, SmallPrimes) {
  // Generate small primes (8 bits)
  cpp_int prime = Primes::generatePrime(8);
  EXPECT_GE(prime, 128); // Lower bound for 8 bits (2^7)
  EXPECT_LT(prime, 256); // Upper bound for 8 bits (2^8)
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(prime)); // Verify primality
}

TEST(GeneratePrimesTest, MediumPrimes) {
  // Generate medium-sized primes (16 bits)
  cpp_int prime = Primes::generatePrime(16);
  EXPECT_GE(prime, 32768); // Lower bound for 16 bits (2^15)
  EXPECT_LT(prime, 65536); // Upper bound for 16 bits (2^16)
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(prime)); // Verify primality
}

TEST(GeneratePrimesTest, BoundaryCases) {
  // Smallest valid prime (2 bits)
  cpp_int prime = Primes::generatePrime(2);
  EXPECT_GE(prime, 2); // Lower bound for 2 bits
  EXPECT_LT(prime, 4); // Upper bound for 2 bits
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(prime)); // Verify primality
}

TEST(GeneratePrimesTest, LargePrimes) {
  // Generate large primes (512 bits)
  cpp_int prime = Primes::generatePrime(512);
  cpp_int lower_bound = cpp_int(1) << 511;       // 2^511
  cpp_int upper_bound = (cpp_int(1) << 512) - 1; // 2^512 - 1
  EXPECT_GE(prime, lower_bound);                 // Lower bound for 512 bits
  EXPECT_LT(prime, upper_bound);                 // Upper bound for 512 bits
  EXPECT_TRUE(Primes::MillerRabinPrimalityTest(prime)); // Verify primality
}

TEST(GeneratePrimesTest, RejectInvalidBitLengths) {
  // Invalid bit lengths should throw an exception
  EXPECT_THROW(Primes::generatePrime(1),
               std::runtime_error); // Less than 3 bits
  EXPECT_THROW(Primes::generatePrime(0), std::runtime_error);  // Zero bits
  EXPECT_THROW(Primes::generatePrime(-5), std::runtime_error); // Negative bits
}

// Main entry point for the test runner
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
