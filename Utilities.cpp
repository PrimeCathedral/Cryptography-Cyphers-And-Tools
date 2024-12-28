//
// Created by Jimmy on 12/22/24.
//

#include "Utilities.h"
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

namespace Crypto {

    std::random_device rd;
    std::mt19937 gen(rd());  // Mersenne Twister engine

    int Utilities::random(const int min, const int max) {
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    // This function runs a single test of Fermat's Primality Test with the base being 2. 2^(p-1) mod p = 1
    bool Utilities::FermatPrimalityTest(int p, int a) {
      if (!std::gcd(p, a)) return false;
      if (int(std::pow(a, p - 1)) % p != 1) return false;
      return true;
    }

    int Utilities::modularExponentiation(
        const boost::multiprecision::cpp_int base,
        const boost::multiprecision::cpp_int power,
        const boost::multiprecision::cpp_int mod) {

        // Edge cases 0 and 1
        if (power == 0) return 1;
        if (base == 0) return 0;

        std::size_t bit_count {0};

        // Find the total number of bits in the power(?)
        for (const auto& temp {power}; temp != 0; temp >> 1) {
            bit_count++;
        }

        //

        return result;
    }
} //