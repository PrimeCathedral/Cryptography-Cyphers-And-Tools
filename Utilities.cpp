//
// Created by Jimmy on 12/22/24.
//

#include "Utilities.h"

namespace Crypto {

    std::random_device rd;
    std::mt19937 gen(rd());  // Mersenne Twister engine

    int Utilities::random(int min, int max) {
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    // This function runs a single test of Fermats Primality Test with the base being 2. 2^(p-1) mod p = 1
    bool Utilities::FermatPrimalityTest(int p, int a) {
      if (!std::gcd(p, a)) return false;
      if (int(std::pow(a, p - 1)) % p != 1) return false;
      return true;
    }

    int Utilities::modularExponentiation(int base, int power, int mod) {
      // Edge cases 0 and 1
      if (power == 0) return 1;
      if (base == 0) return 0;

      // Set result to be the base
      auto result {base};

      // For every bit in an 8 bit int (from left to right)
      for(auto i {7}; i >= 0; --i) {

          // Always square the result
          result = (result * result) % mod;

           // Shift to see the i-th bit in the leftmost position (64 = 10000000)
           if ((64 & (power << (7-i))) != 0) {
              // If bit is 1, also multiply
              result = result * base % mod;
           }
      }

      // Return the calculated value
      return result;
    }
} //