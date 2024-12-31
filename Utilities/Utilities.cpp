//
// Created by Jimmy on 12/31/24.
//

#include "Utilities.h"

using cpp_int = boost::multiprecision::cpp_int;

cpp_int Utilities::binaryExponentiation(const cpp_int& base, const cpp_int& power) {

    // Edge cases
    if (base == 0 && power == 0) return 1;
    if (base == 0) return 0;
    if (power == 0) return 1;

    // Initialize variables
    cpp_int power_copy {power};
    cpp_int result {1};
    cpp_int base_copy {base};

    // While power has bits to calculate
    while (power_copy > 0) {

        // If the current bit is 1, multiply result by base
        if (power_copy & 1) result *= base_copy;

        // Square the base regardless of the current bit
        base_copy *= base_copy;

        // Shift bits in power one to the right
        power_copy >>= 1;
    }
    return result;
}