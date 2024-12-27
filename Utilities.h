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
// #include <boost/version.hpp>

namespace Crypto {

class Utilities {

    public:
        static int random(int min, int max);
        static bool FermatPrimalityTest(int p, int a);
        static int modularExponentiation(uint64_t base, uint64_t power, uint64_t mod);
};

} // Crypto

#endif //UTILITIES_H
