//
// Created by Jimmy on 1/3/25.
//
#include "../Utilities/IntegerFactorization.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <gtest/gtest.h>
#include <vector>

using boost::multiprecision::cpp_int;

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

TEST_F(IntegerFactorizationTest, TrialDivision_PrimeNumber) {
  const cpp_int number = 13;
  IntegerFactorization::TrialDivision(number, factors);
  assertFactors(number, {13});
}

TEST_F(IntegerFactorizationTest, TrialDivision_CompositeNumber) {
  const cpp_int number = 12;
  IntegerFactorization::TrialDivision(number, factors);
  assertFactors(number, {2, 2, 3});
}

TEST_F(IntegerFactorizationTest, TrialDivision_NegativeNumber) {
  const cpp_int number = -18;
  IntegerFactorization::TrialDivision(number, factors);
  assertFactors(number, {2, 3, 3, -1});
}

TEST_F(IntegerFactorizationTest, TrialDivision_Zero) {
  const cpp_int number = 0;
  EXPECT_THROW(IntegerFactorization::TrialDivision(number, factors),
               std::invalid_argument);
}

TEST_F(IntegerFactorizationTest, WheelFactorization_PrimeNumber) {
  const cpp_int number = 19;
  IntegerFactorization::WheelFactorization(number, factors);
  assertFactors(number, {19});
}

TEST_F(IntegerFactorizationTest, WheelFactorization_CompositeNumber) {
  const cpp_int number = 30;
  IntegerFactorization::WheelFactorization(number, factors);
  assertFactors(number, {2, 3, 5});
}

TEST_F(IntegerFactorizationTest, WheelFactorization_NegativeNumber) {
  const cpp_int number = -42;
  IntegerFactorization::WheelFactorization(number, factors);
  assertFactors(number, {2, 3, 7, -1});
}

TEST_F(IntegerFactorizationTest, WheelFactorization_Zero) {
  const cpp_int number = 0;
  EXPECT_THROW(IntegerFactorization::WheelFactorization(number, factors),
               std::invalid_argument);
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_PrimeNumbers) {
  const cpp_int n = 20;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(n, {false, false, true,  true,  false, true,  false,
                   true,  false, false, false, true,  false, true,
                   false, false, false, true,  false, true,  false});
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_NoPrimes) {
  const cpp_int n = 1;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(n, {false, false});
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_PrimeNumberEdgeCase) {
  const cpp_int n = 2;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(n, {false, false, true});
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_LargePrimeNumber) {
  const cpp_int n = 100;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(
      n, {false, false, true,  true,  false, true,  false, true,  false, false,
          false, true,  false, true,  false, false, false, true,  false, true,
          false, false, false, true,  false, false, false, false, false, true,
          false, true,  false, false, false, false, false, true,  false, false,
          false, true,  false, true,  false, false, false, true,  false, false,
          false, false, false, true,  false, false, false, false, false, true,
          false, true,  false, false, false, false, false, true,  false, false,
          false, true,  false, true,  false, false, false, false, false, true,
          false, false, false, true,  false, false, false, false, false, true,
          false, false, false, false, false, false, false, true,  false, false,
          false});
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_Zero) {
  const cpp_int n = 0;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(n, {false});
}

TEST_F(SieveOfEratosthenesTest, SieveOfEratosthenes_SingleNumber) {
  const cpp_int n = 1;
  primes = IntegerFactorization::SieveOfEratosthenes(n);
  assertPrimes(n, {false, false});
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
