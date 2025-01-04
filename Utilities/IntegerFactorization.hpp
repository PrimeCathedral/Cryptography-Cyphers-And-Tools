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
    static std::vector<cpp_int>& TrialDivision(const cpp_int& number);
    static std::vector<cpp_int> WheelFactorization(const cpp_int& number);
};



#endif //INTEGERFACTORIZATION_HPP
