//
// Created by Jimmy on 12/22/24.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdexcept>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

namespace Crypto {

class ModularArithmetic {

    public:
        static cpp_int extendedGCD(cpp_int base, const cpp_int& modulus, cpp_int& x, cpp_int& y);
        static cpp_int modularMultiplicativeInverse(const cpp_int & base, const cpp_int & modulus);
        static cpp_int modularExponentiation(const cpp_int& base, const cpp_int& power, const cpp_int& mod);
};

} // Crypto

#endif //UTILITIES_H
