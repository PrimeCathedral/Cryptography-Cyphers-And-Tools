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

using namespace boost::multiprecision;

namespace Crypto {

class Utilities {

    public:
        static int random(int min, int max);
        static bool FermatPrimalityTest(int p, int a);
        static cpp_int modularExponentiation(const cpp_int& base, const cpp_int& power, const cpp_int& mod);
};

} // Crypto

#endif //UTILITIES_H
