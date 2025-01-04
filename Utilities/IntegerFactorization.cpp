//
// Created by Jimmy on 1/3/25.
//

#include "IntegerFactorization.hpp"

using cpp_int = boost::multiprecision::cpp_int;

// TODO: optimize these with pointer usages. Return factors vector as a pointer to avoid copying the large numbers

// Please never use this one
std::vector<cpp_int>& IntegerFactorization::TrialDivision(const cpp_int& number) {
    // This vector will contain all prime factors of number
    std::vector<cpp_int>* factors {new std::vector<cpp_int>()};
    auto composite {number};

    // Start at 2 and go all the way to √number
    for (cpp_int factor {2}; factor * factor <= composite; ++factor) {
        // Repeat while factor is in number. For example 8 = 2 * 2 * 2
        while (composite % factor == 0) {
            // Add factor to vector
            factors->emplace_back(factor);
            // Update number accordingly
            composite = composite / factor;
        }
    }

    if (composite > 1) factors->emplace_back(composite);

    return *factors;
}

std::vector<cpp_int> IntegerFactorization::WheelFactorization(const cpp_int& number) {
    std::vector<cpp_int> factors;
    auto composite {number};

    // Eliminate/add all even factors (this eliminates 50% of numbers to try)
    while (composite % 2 == 0) {
        factors.emplace_back(2);
        composite /= 2;
    }

    // Find odd factors
    for (cpp_int factor {3}; factor * factor <= composite; factor += 2) {
        while (composite % factor == 0) {
            factors.emplace_back(factor);
            composite /= factor;
        }
    }

    if (composite > 1) factors.emplace_back(composite);
    return factors;
}
