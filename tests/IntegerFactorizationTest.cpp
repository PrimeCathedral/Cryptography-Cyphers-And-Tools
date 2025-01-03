//
// Created by Jimmy on 1/3/25.
//

#include <gtest/gtest.h>
#include <boost/multiprecision/cpp_int.hpp>
#include "../Utilities/IntegerFactorization.hpp"

using cpp_int = boost::multiprecision::cpp_int;

TEST(FactorizationTests, TrialDivisionEdgeCases) {
    // 1 has no prime factors
    EXPECT_EQ(IntegerFactorization::TrialDivision(1).size(), 0);

    // Prime number
    EXPECT_EQ(IntegerFactorization::TrialDivision(13), std::vector<cpp_int>({13}));

    // Composite number with distinct primes
    EXPECT_EQ(IntegerFactorization::TrialDivision(30), std::vector<cpp_int>({2, 3, 5}));

    // Composite number with repeated primes
    EXPECT_EQ(IntegerFactorization::TrialDivision(60), std::vector<cpp_int>({2, 2, 3, 5}));

    // Large prime number
    EXPECT_EQ(IntegerFactorization::TrialDivision(cpp_int("104729")), std::vector<cpp_int>({104729}));

    // Large composite number
    EXPECT_EQ(IntegerFactorization::TrialDivision(cpp_int("123456")), std::vector<cpp_int>({2, 2, 2, 2, 2, 3, 643}));
}

TEST(FactorizationTests, WheelFactorizationEdgeCases) {
    // 1 has no prime factors
    EXPECT_EQ(IntegerFactorization::WheelFactorization(cpp_int(1)).size(), 0);

    // Prime number
    EXPECT_EQ(IntegerFactorization::WheelFactorization(cpp_int(13)), std::vector<cpp_int>({13}));

    // Composite number with distinct primes
    EXPECT_EQ(IntegerFactorization::WheelFactorization(cpp_int(30)), std::vector<cpp_int>({2, 3, 5}));

    // Composite number with repeated primes
    EXPECT_EQ(IntegerFactorization::WheelFactorization(cpp_int(60)), std::vector<cpp_int>({2, 2, 3, 5}));

    // Large prime number
    EXPECT_EQ(IntegerFactorization::WheelFactorization(cpp_int("104729")), std::vector<cpp_int>({104729}));

    // Large composite number
    EXPECT_EQ(IntegerFactorization::WheelFactorization(cpp_int("123456")), std::vector<cpp_int>({2, 2, 2, 2, 2, 3, 643}));
}

TEST(FactorizationTests, CompareTrialAndWheel) {
    // Compare the results of both methods
    EXPECT_EQ(IntegerFactorization::TrialDivision(cpp_int(30)), IntegerFactorization::WheelFactorization(cpp_int(30)));
    EXPECT_EQ(IntegerFactorization::TrialDivision(cpp_int(60)), IntegerFactorization::WheelFactorization(cpp_int(60)));
    EXPECT_EQ(IntegerFactorization::TrialDivision(cpp_int("123456")), IntegerFactorization::WheelFactorization(cpp_int("123456")));
    EXPECT_EQ(IntegerFactorization::TrialDivision(cpp_int("104729")), IntegerFactorization::WheelFactorization(cpp_int("104729")));
}


// Main entry point for the test runner
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
