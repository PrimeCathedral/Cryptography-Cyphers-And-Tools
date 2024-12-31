//
// Created by Jimmy on 12/22/24.
//

#include "ModularArithmetic.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_int.hpp>

namespace Crypto {

    /**
     * Computes the Extended Euclidean Algorithm for the given inputs.
     *
     * @param base The first number (a).
     * @param modulus The second number (b).
     * @param x Output parameter representing the coefficient for base in the equation ax + by = gcd(a, b).
     * @param y Output parameter representing the coefficient for modulus in the equation ax + by = gcd(a, b).
     * @return The greatest common divisor (gcd) of base and modulus.
     */
    cpp_int ModularArithmetic::extendedGCD(cpp_int base, const cpp_int& modulus, cpp_int& x, cpp_int& y) {
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

    /**
     * Checks if a given number is negative.
     *
     * @param x The number to check.
     * @return True if the number is negative, false otherwise.
     */
    bool isNegative(const cpp_int &x) {
        if (x < 0) return true;
        return false;
    }

    /**
     * Computes the modular multiplicative inverse of a given base under a given modulus.
     *
     * @param base The number for which to compute the inverse.
     * @param modulus The modulus under which the inverse is computed.
     * @return The modular multiplicative inverse of base under modulus.
     * @throws std::runtime_error If the modulus is 1 or if the inverse does not exist (gcd(base, modulus) != 1).
     */
    cpp_int ModularArithmetic::modularMultiplicativeInverse(const cpp_int& base, const cpp_int& modulus) {

        cpp_int base_copy      {base};
        cpp_int modulus_copy   {modulus};

        // Ensure the modulo is always positive before computing the inverse
        if (isNegative(modulus_copy)) modulus_copy = -modulus_copy;

        // Ensure the base is always positive
        if (isNegative(base_copy)) base_copy = -base_copy;

        // Multiplicative inverse under modulus 1 does not exist
        if (modulus == 1) throw std::runtime_error("Multiplicative Inverse under Modulo = 1 does not exist.");

        cpp_int x, y;
        cpp_int gcd {extendedGCD(base_copy, modulus_copy, x, y)};

        if (gcd != 1) {
            throw std::runtime_error("Modular inverse does not exist");
        }

        // Calculate the inverse
        cpp_int result {(x % modulus + modulus) % modulus};

        return result;
    }

    /**
     * Performs modular exponentiation: computes (base^power) % mod.
     *
     * @param base The base of the exponentiation.
     * @param power The exponent.
     * @param mod The modulus.
     * @return The result of (base^power) % mod.
     * @throws std::runtime_error If power and base are both 0 (undefined) or if mod is invalid.
     */
    cpp_int ModularArithmetic::modularExponentiation(const cpp_int& base, const cpp_int& power, const cpp_int& mod) {
        // Edge cases
        if (power == 0 && base == 0) throw std::runtime_error("Math Error: 0^0 is undefined.");
        if (power == 0) return 1;
        if (power == -1) {
            return modularMultiplicativeInverse(base, mod);
        }
        if (power == 1) return base % mod;
        if (base == 0)  return 0;

        // Set the result to be the base so we start with b^1
        cpp_int result{base};
        if (result > mod) result %= mod;
        if (result == mod) return 1;

        // Find out how many bits the exponent has
        std::size_t current_bit {msb(power)};
        constexpr std::size_t rightmost_bit {0};

        // While there are bits left to compute
        do {
            // Square the result
            result = (result * result) % mod;

            // If the current bit is 1
            if (1 & (power >> (current_bit - 1))) {
                // Multiply by base
                result = (result * base) % mod;
            }

            // Go right one bit
            current_bit--;

        } while (current_bit != rightmost_bit);

        // Return the calculated value
        return result;
    }

    cpp_int binaryExponentiation(cpp_int base, cpp_int power) {

        // Edge cases
        if (base == 0 && power == 0) throw std::runtime_error("Math Error: 0^0 is undefined.");
        if (base == 0) return 0;
        if (power == 0) return 1;

        // Initialize variables
        cpp_int result {1};

        // While power has bits to calculate
        while (power > 0) {

            // If the current bit is 1, multiply result by base
            if (power & 1) result *= base;

            // Regardless of value of bit, square the result
            base *= base;

            // Shift bits in power one to the right
            power >>= 1;
        }
        return result;

    }
} // namespace Crypto
