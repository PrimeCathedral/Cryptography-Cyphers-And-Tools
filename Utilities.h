//
// Created by Jimmy on 12/22/24.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <cmath>
#include <numeric>
#include <iostream>
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

#define mp boost::multiprecision

namespace Crypto {

class Utilities {

    public:
        static int random(int min, int max);
        static bool FermatPrimalityTest(int p, int a);
        static mp::cpp_int modularInverse(mp::cpp_int base, mp::cpp_int modulus);
        static mp::cpp_int modularExponentiation(const mp::cpp_int& base, const mp::cpp_int& power, const mp::cpp_int& mod);
};

} // Crypto

#endif //UTILITIES_H
