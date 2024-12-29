//
// Created by Jimmy on 12/22/24.
//

#include "Utilities.h"

#include <stdexcept>
#include <boost/multiprecision/cpp_int.hpp>

namespace Crypto {

    std::random_device rd;
    std::mt19937 gen(rd());  // Mersenne Twister engine

    int Utilities::random(const int min, const int max) {
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    cpp_int Utilities::modularExponentiation(const cpp_int& base, const cpp_int& power, const cpp_int& mod) {

        // Edge cases 0 and 1
        if (power == 0 && base == 0) throw std::runtime_error("Math Error: 0^0 is undefined.");
        if (power == 0) return 1;
        if (base == 0) return 0;

        // Set the result to be the base so we start with b^1
        cpp_int result{base};
        if (result > mod) result %= mod;
        else if (result == mod) return 1;


        // Find out how many bits the exponent has
        // Leftmost bit is actually the INDEX of the most significant
        // bit, basing at zero. So if power has 10 bits, leftmost will
        // contain 9.
        const std::size_t leftmost_bit_in_power {boost::multiprecision::msb(power)};

        constexpr std::size_t rightmost_bit {0};
        // For every bit in the exponent (from left to right)
        for (auto current_bit {leftmost_bit_in_power}; current_bit >= 0; --current_bit) {

            // Square the result
            result = (result * result) % mod;

            // If the current bit is 1
            if (power >> current_bit & 1) {
               // Multiply by base
                result = (result * base) % mod;
            }
            // Break the loop after the rightmost bit has been analyzed
            if (current_bit == rightmost_bit) break;
        }
        // Return the calculated value
        return result;
    }
} //