//
// Created by Jimmy on 1/3/25.
//
#include "../Utilities/IntegerFactorization.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <gtest/gtest.h>
#include <vector>

using cpp_int = boost::multiprecision::cpp_int;

class IntegerFactorizationTest : public ::testing::Test {
protected:
  std::vector<cpp_int> factors;

  void assertFactors(const cpp_int &number,
                     const std::vector<cpp_int> &expectedFactors) const {
    cpp_int product = 1;
    for (const auto &factor : factors) {
      product *= factor;
    }
    EXPECT_EQ(product, number)
        << "Factors do not multiply to the original number.";
    EXPECT_EQ(factors, expectedFactors)
        << "Factors do not match expected values.";
  }
};

TEST_F(IntegerFactorizationTest, TrialDivision_PrimeNumber) {
  cpp_int number = 13;
  IntegerFactorization::TrialDivision(number, factors);
  assertFactors(number, {13});
}

TEST_F(IntegerFactorizationTest, TrialDivision_CompositeNumber) {
  cpp_int number = 12;
  IntegerFactorization::TrialDivision(number, factors);
  assertFactors(number, {2, 2, 3});
}

TEST_F(IntegerFactorizationTest, TrialDivision_NegativeNumber) {
  cpp_int number = -18;
  IntegerFactorization::TrialDivision(number, factors);
  assertFactors(number, {2, 3, 3, -1});
}

TEST_F(IntegerFactorizationTest, TrialDivision_Zero) {
  cpp_int number = 0;
  EXPECT_THROW(IntegerFactorization::TrialDivision(number, factors),
               std::invalid_argument);
}

TEST_F(IntegerFactorizationTest, WheelFactorization_PrimeNumber) {
  cpp_int number = 19;
  IntegerFactorization::WheelFactorization(number, factors);
  assertFactors(number, {19});
}

TEST_F(IntegerFactorizationTest, WheelFactorization_CompositeNumber) {
  cpp_int number = 30;
  IntegerFactorization::WheelFactorization(number, factors);
  assertFactors(number, {2, 3, 5});
}

TEST_F(IntegerFactorizationTest, WheelFactorization_NegativeNumber) {
  cpp_int number = -42;
  IntegerFactorization::WheelFactorization(number, factors);
  assertFactors(number, {2, 3, 7, -1});
}

TEST_F(IntegerFactorizationTest, WheelFactorization_Zero) {
  cpp_int number = 0;
  EXPECT_THROW(IntegerFactorization::WheelFactorization(number, factors),
               std::invalid_argument);
}

class SieveOfEratosthenesTest : public ::testing::Test {
protected:
  std::vector<bool> primes;

  void assertPrimes(const cpp_int &n,
                    const std::vector<bool> &expectedPrimes) const {
    for (cpp_int i = 0; i <= n; ++i) {
      EXPECT_EQ(primes[i.convert_to<long long>()],
                expectedPrimes[i.convert_to<long long>()])
          << "Primes do not match at index " << i;
    }
  }
};

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_PrimeNumbers) {
  cpp_int n = 20;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  //                                0      1      2     3     4      5     6 7
  //                                8      9      10     11    12     13    14
  //                                15    16     17    18     19     20
  assertPrimes(n, {false, false, true,  true,  false, true,  false,
                   true,  false, false, false, true,  false, true,
                   false, false, false, true,  false, true,  false});
  //                             index 0   index 1   index 2   index 3   index 4
  //                             index 5  index 6   index 7  index 8  index 9
  //                             index 10  index 11 index 12  index 13  index 14
  //                             index 15  index 16  index 17 index 18  index 19
  //                             index 20
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_NoPrimes) {
  cpp_int n = 1;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(n, {false, false});
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_PrimeNumberEdgeCase) {
  cpp_int n = 2;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(n, {false, false, true});
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_LargePrimeNumber) {
  cpp_int n = 100;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(
      n,
      {false, false, true,  true,  false, true,
       false, true,  false, false, // 00 01 02 03 04 05 06 07 08 09
       false, true,  false, true,  false, false,
       false, true,  false, true, // 10 11 12 13 14 15 16 17 18 19
       false, false, false, true,  false, false,
       false, false, false, true, // 20 21 22 23 24 25 26 27 28 29
       false, true,  false, false, false, false,
       false, true,  false, false, // 30 31 32 33 34 35 36 37 38 39
       false, true,  false, true,  false, false,
       false, true,  false, false, // 40 41 42 43 44 45 46 47 48 49
       false, false, false, true,  false, false,
       false, false, false, true, // 50 51 52 53 54 55 56 57 58 59
       false, true,  false, false, false, false,
       false, true,  false, false, // 60 61 62 63 64 65 66 67 68 69
       false, true,  false, true,  false, false,
       false, false, false, true, // 70 71 72 73 74 75 76 77 78 79
       false, false, false, true,  false, false,
       false, false, false, true, // 80 81 82 83 84 85 86 87 88 89
       false, false, false, false, false, false,
       false, true,  false, false, false}); // 90 91 92 93 94 95 96 97 98 99 100
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_Zero) {
  cpp_int n = 0;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(n, {false});
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_SingleNumber) {
  cpp_int n = 1;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(n, {false, false});
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
