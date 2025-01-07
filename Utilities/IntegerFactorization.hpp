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
    static void TrialDivision(const cpp_int& number, std::vector<cpp_int>& factors);
    static void WheelFactorization(const cpp_int& number, std::vector<cpp_int>& factors);
};



#endif //INTEGERFACTORIZATION_HPP
