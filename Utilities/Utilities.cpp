//
// Created by Jimmy on 12/31/24.
//

#include "Utilities.hpp"

using boost::multiprecision::cpp_int;

/**
 * Checks if a given number is odd.
 *
 * A number is considered odd if its least significant bit is 1.
 *
 * @param number The number to check.
 * @return True if the number is odd, false otherwise.
 */
bool Utilities::isOdd(const cpp_int &number) {
  // If the rightmost bit is one, it is odd
  return (number & 1) == 1;
}

/**
 * Checks if a given number is even.
 *
 * A number is considered even if its least significant bit is 0.
 *
 * @param number The number to check.
 * @return True if the number is even, false otherwise.
 */
bool Utilities::isEven(const cpp_int &number) {
  // If the rightmost bit is one, it is odd
  return (number & 1) == 0;
}

/**
 * Checks if a given number is positive.
 *
 * A number is positive if it is greater than 0.
 *
 * @param number The number to check.
 * @return True if the number is positive, false otherwise.
 */
bool Utilities::isPositive(const cpp_int &number) { return (number > 0); }

/**
 * Checks if a given number is negative.
 *
 * A number is negative if it is less than 0.
 *
 * @param number The number to check.
 * @return True if the number is negative, false otherwise.
 */
bool Utilities::isNegative(const cpp_int &number) { return (number < 0); }

bool Utilities::isNotPositive(const cpp_int &number) { return (number <= 0); }

bool Utilities::isNotNegative(const cpp_int &number) { return (number >= 0); }

/**
 * Computes the result of raising a base to a power using binary exponentiation.
 *
 * This function uses the binary exponentiation algorithm, which is efficient
 * and operates in \O(log(power)).
 *
 * @param base The base to be raised to the given power.
 * @param power The exponent to which the base is raised. Must be non-negative.
 * @return The result of (base^power). If the base is negative and odd, the
 * result is negative.
 * @throws std::runtime_error If the power is negative (not yet implemented).
 */
cpp_int Utilities::binaryExponentiation(const cpp_int &base,
                                        const cpp_int &power) {
  // Edge cases
  // TODO define negative exponent functionality. Might have to refer to
  // cpp_rational because fractions and cpp_int is unsigned(maybe)
  if (power < 0)
    throw std::runtime_error(
        "Negative exponent functionality not yet defined.");
  if (base == 0 && power == 0)
    return 1; // Convention: 0^0 is 1
  if (base == 0)
    return 0; // 0^x = 0 for x > 0
  if (power == 0)
    return 1; // x^0 = 1 for any x != 0

  // Initialize variables
  cpp_int power_copy{power};
  cpp_int result{1};
  cpp_int base_copy{base};

  // Perform binary exponentiation
  while (power_copy > 0) {
    // If the current bit is 1, multiply result by base
    if (power_copy & 1)
      result *= base_copy;

    // Square the base for the next bit
    base_copy *= base_copy;

    // Shift bits in power one to the right
    power_copy >>= 1;
  }

  return result;
}
