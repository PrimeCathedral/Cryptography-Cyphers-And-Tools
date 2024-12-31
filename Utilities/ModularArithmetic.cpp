//
// Created by Jimmy on 12/22/24.
//

#include "ModularArithmetic.h"

#include <stdexcept>

namespace Crypto {

    std::random_device rd;
    std::mt19937 gen(rd());  // Mersenne Twister engine

    int ModularArithmetic::random(const int min, const int max) {
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    cpp_int ModularArithmetic::extendedGCD(cpp_int base, cpp_int modulus, cpp_int& x, cpp_int& y) {
        if (modulus == 0) {
            x = 1;
            y = 0;
            return base;
        }

        cpp_int x1, y1;
        cpp_int gcd {extendedGCD(modulus, base % modulus, x1, y1)};

        x = y1;
        y = x1 - (base / modulus) * y1;

        return gcd;
    }

    // This function is here purely to improve code readability
    bool isNegative(cpp_int x) {
        if (x < 0) return true;
        return false;
    }

    cpp_int ModularArithmetic::modularInverse(cpp_int base, cpp_int modulus) {

        // Ensure the modulo is always positive before computing the inverse
        if (isNegative(modulus)) modulus = -modulus;

        // Ensure the base is always positive (negatives do not exist in modulo)
        // if (isNegative(base)) base = (base % modulus + modulus) % modulus;
        if (isNegative(base)) base = -base;

        // Multiplicative inverse under 1 does not exist
        if (modulus == 1) throw std::runtime_error("Multiplicative Inverse under Modulo = 1 does not exist.");

        cpp_int x, y;
        cpp_int gcd = extendedGCD(base, modulus, x, y);

        if (gcd != 1) {
            throw std::runtime_error("Modular inverse does not exist");
        }

            // Calculate the inverse
        cpp_int result {(x % modulus + modulus) % modulus};

        return result;
    }

    cpp_int ModularArithmetic::modularExponentiation(const cpp_int& base, const cpp_int& power, const cpp_int& mod) {

        // Edge cases 0 and 1
        if (power == 0 && base == 0) throw std::runtime_error("Math Error: 0^0 is undefined.");
        if (power == 0) return 1;
        if (power == -1) {
            return modularInverse(base, mod);
            // TODO check if this is really what I want to return on powm(base, power, mod)
        }
        if (power == 1) return base % mod;
        if (base == 0)  return 0;

        // Set the result to be the base so we start with b^1
        cpp_int result{base};
        if (result > mod) result %= mod;
        if (result == mod) return 1;

        // Find out how many bits the exponent has
        // Leftmost bit is actually the INDEX of the most significant
        // bit, basing at zero. So if power has 10 bits, leftmost will
        // contain 9.
        std::size_t current_bit {msb(power)};
        constexpr std::size_t rightmost_bit {0};

        // While there are bits left to compute
        do {
            // Square the result
            result = (result * result) % mod;

            // If the current bit is 1
            if (1 & (power >> (current_bit-1))) {
                // Multiply by base
                result = (result * base) % mod;
            }

            // Go right one bit
            current_bit--;

        } while (current_bit != rightmost_bit);

        // Return the calculated value
        return result;
    }
} //