//
// Created by Jimmy on 12/22/24.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include <random>
#include <cmath>
#include <numeric>
#include <iostream>

namespace Crypto {

class Utilities {

    public:
        int random(int min, int max);
        bool FermatPrimalityTest(int p, int a);
        int modularExponentiation(int base, int power, int mod);
};

} // Crypto

#endif //UTILITIES_H
