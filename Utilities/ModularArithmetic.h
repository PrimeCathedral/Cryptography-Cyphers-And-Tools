//
// Created by Jimmy on 12/28/24.
//

#ifndef MODULARARITHMETIC_H
#define MODULARARITHMETIC_H

#include <boost/multiprecision/cpp_int.hpp>

class ModularArithmetic {
    using cpp_int = boost::multiprecision::cpp_int;
private:
    cpp_int mod {}; // The modulus for all operations

public:
    explicit ModularArithmetic(const cpp_int& mod);

    cpp_int add(const cpp_int &a, const cpp_int &b);
    cpp_int substract(const cpp_int &a, const cpp_int &b);
    cpp_int multiply(const cpp_int &a, const cpp_int &b);
    cpp_int divide(const cpp_int &a, const cpp_int &b); // TODO implement modular division
    cpp_int power(const cpp_int &a, const cpp_int &b);
    cpp_int inverse(const cpp_int &a); // Find modular inverse

};



#endif //MODULARARITHMETIC_H
