//
// Created by Jimmy on 1/3/25.
//

#include <gtest/gtest.h>
#include <boost/multiprecision/cpp_int.hpp>
#include "../Utilities/IntegerFactorization.hpp"

using cpp_int = boost::multiprecision::cpp_int;

/**
 * Helper function to compute the product of all elements in a vector.
 * @param factors The vector containing factors.
 * @return The product of all factors in the vector.
 */
cpp_int productOfFactors(const std::vector<cpp_int>& factors) {
    cpp_int product = 1;
    for (const auto& factor : factors) {
        product *= factor;
    }
    return product;
}

TEST(FactorizationTests, TrialDivisionEdgeCases) {
    // Test with 1 (no factors)
    const auto factors_1 = IntegerFactorization::TrialDivision(cpp_int(1));
    EXPECT_EQ(factors_1.size(), 0);
    EXPECT_EQ(productOfFactors(factors_1), 1);

    // Test with a prime number
    const auto factors_prime = IntegerFactorization::TrialDivision(cpp_int(13));
    EXPECT_EQ(factors_prime.size(), 1);
    EXPECT_EQ(productOfFactors(factors_prime), 13);

    // Test with a composite number (distinct primes)
    const auto factors_30 = IntegerFactorization::TrialDivision(cpp_int(30));
    EXPECT_EQ(factors_30.size(), 3); // Factors: 2, 3, 5
    EXPECT_EQ(productOfFactors(factors_30), 30);

    // Test with a composite number (repeated primes)
    const auto factors_60 = IntegerFactorization::TrialDivision(cpp_int(60));
    EXPECT_EQ(factors_60.size(), 4); // Factors: 2, 2, 3, 5
    EXPECT_EQ(productOfFactors(factors_60), 60);

    // Test with a large prime number
    const auto factors_large_prime = IntegerFactorization::TrialDivision(cpp_int("104729"));
    EXPECT_EQ(factors_large_prime.size(), 1);
    EXPECT_EQ(productOfFactors(factors_large_prime), cpp_int("104729"));

    // Test with a large composite number
    const auto factors_large_composite = IntegerFactorization::TrialDivision(cpp_int("123456"));
    EXPECT_EQ(factors_large_composite.size(), 8); // Factors: 2, 2, 2, 2, 2, 2, 3, 643
    EXPECT_EQ(productOfFactors(factors_large_composite), cpp_int("123456"));
}

TEST(FactorizationTests, WheelFactorizationEdgeCases) {
    // Test with 1 (no factors)
    const auto factors_1 = IntegerFactorization::WheelFactorization(cpp_int(1));
    EXPECT_EQ(factors_1.size(), 0);
    EXPECT_EQ(productOfFactors(factors_1), 1);

    // Test with a prime number
    const auto factors_prime = IntegerFactorization::WheelFactorization(cpp_int(13));
    EXPECT_EQ(factors_prime.size(), 1);
    EXPECT_EQ(productOfFactors(factors_prime), 13);

    // Test with a composite number (distinct primes)
    const auto factors_30 = IntegerFactorization::WheelFactorization(cpp_int(30));
    EXPECT_EQ(factors_30.size(), 3); // Factors: 2, 3, 5
    EXPECT_EQ(productOfFactors(factors_30), 30);

    // Test with a composite number (repeated primes)
    const auto factors_60 = IntegerFactorization::WheelFactorization(cpp_int(60));
    EXPECT_EQ(factors_60.size(), 4); // Factors: 2, 2, 3, 5
    EXPECT_EQ(productOfFactors(factors_60), 60);

    // Test with a large prime number
    const auto factors_large_prime = IntegerFactorization::WheelFactorization(cpp_int("104729"));
    EXPECT_EQ(factors_large_prime.size(), 1);
    EXPECT_EQ(productOfFactors(factors_large_prime), cpp_int("104729"));

    // Test with a large composite number
    const auto factors_large_composite = IntegerFactorization::WheelFactorization(cpp_int("123456"));
    EXPECT_EQ(factors_large_composite.size(), 7); // Factors: 2, 2, 2, 2, 2, 3, 643
    EXPECT_EQ(productOfFactors(factors_large_composite), cpp_int("123456"));
}

TEST(FactorizationTests, CompareTrialAndWheel) {
    // Compare results for a composite number
    const auto trial_factors_30 = IntegerFactorization::TrialDivision(cpp_int(30));
    const auto wheel_factors_30 = IntegerFactorization::WheelFactorization(cpp_int(30));
    EXPECT_EQ(trial_factors_30, wheel_factors_30);

    const auto trial_factors_60 = IntegerFactorization::TrialDivision(cpp_int(60));
    const auto wheel_factors_60 = IntegerFactorization::WheelFactorization(cpp_int(60));
    EXPECT_EQ(trial_factors_60, wheel_factors_60);

    // Compare results for a large composite number
    const auto trial_factors_large = IntegerFactorization::TrialDivision(cpp_int("123456"));
    const auto wheel_factors_large = IntegerFactorization::WheelFactorization(cpp_int("123456"));
    EXPECT_EQ(trial_factors_large, wheel_factors_large);

    // Compare results for a large prime number
    const auto trial_factors_prime = IntegerFactorization::TrialDivision(cpp_int("104729"));
    const auto wheel_factors_prime = IntegerFactorization::WheelFactorization(cpp_int("104729"));
    EXPECT_EQ(trial_factors_prime, wheel_factors_prime);
}

// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
