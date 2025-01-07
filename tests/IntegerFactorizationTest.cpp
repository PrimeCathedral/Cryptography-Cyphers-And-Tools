//
// Created by Jimmy on 1/3/25.
//
#include <gtest/gtest.h>
#include "../Utilities/IntegerFactorization.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

using cpp_int = boost::multiprecision::cpp_int;

class IntegerFactorizationTest : public ::testing::Test {
protected:
    std::vector<cpp_int> factors;

    void assertFactors(const cpp_int& number, const std::vector<cpp_int>& expectedFactors) const {
        cpp_int product = 1;
        for (const auto& factor : factors) {
            product *= factor;
        }
        EXPECT_EQ(product, number) << "Factors do not multiply to the original number.";
        EXPECT_EQ(factors, expectedFactors) << "Factors do not match expected values.";
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
    EXPECT_THROW(IntegerFactorization::TrialDivision(number, factors), std::invalid_argument);
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
    assertFactors(number, { 2, 3, 7, -1});
}

TEST_F(IntegerFactorizationTest, WheelFactorization_Zero) {
    cpp_int number = 0;
    EXPECT_THROW(IntegerFactorization::WheelFactorization(number, factors), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
