//
// Created by Jimmy on 12/22/24.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <boost/multiprecision/cpp_int.hpp>

// using cpp_int = boost::multiprecision::cpp_int;
using namespace boost::multiprecision;

namespace Crypto {

class ModularArithmetic {

    public:
        static int random(int min, int max);
        static bool FermatPrimalityTest(int p, int a);
        static cpp_int extendedGCD(cpp_int base, cpp_int modulus, cpp_int& x, cpp_int& y);
        static cpp_int modularInverse(cpp_int base, cpp_int modulus);
        static cpp_int modularExponentiation(const cpp_int& base, const cpp_int& power, const cpp_int& mod);
};

} // Crypto

#endif //UTILITIES_H
