//
// Created by Jimmy on 1/3/25.
//

#ifndef INTEGERFACTORIZATION_HPP
#define INTEGERFACTORIZATION_HPP

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

class IntegerFactorization {
    using cpp_int = boost::multiprecision::cpp_int;
public:

    // Uses trial division to compute al prime factors of a given number
    static void TrialDivision(const cpp_int& number, std::vector<cpp_int>& factors);

    // Uses wheel factorization to return all prime factors of a given number
    static void WheelFactorization(const cpp_int& number, std::vector<cpp_int>& factors);

    // Determines prime numbers up to n
    static std::vector<bool> SieveOfEratosthenes(const cpp_int& n);
};



#endif //INTEGERFACTORIZATION_HPP
