//
// Created by Jimmy on 1/3/25.
//

#include "IntegerFactorization.hpp"
#include "Utilities.hpp"

// TODO: find a way to make these functions take only one parameter, the number
// to factorize, and return an array of prime factors, without copying (using
// pointers properly) (maybe a class member vector<cpp_int> factors??)
// TODO 2: Check with professor if Prime factorization should be defined for
// negative numbers

// Please never use this one
void IntegerFactorization::TrialDivision(const cpp_int &number,
                                         vector<cpp_int> &factors) {
  // Make sure the given vector is empty
  factors.clear();

  // Zero has no prime factors
  if (number == 0)
    throw std::invalid_argument(
        "IntegerFactorization::TrialDivision: Zero has no prime factors.");

  // Make a copy of the number for manipulating
  cpp_int composite = number;

  // Treat all input as positive (we change signs at the end)
  if (Utilities::isNegative(composite))
    composite *= -1;

  // Compute the square root. factor(n) !> √n
  const cpp_int sqrt{boost::multiprecision::sqrt(composite)};

  // Start at 2 and go all the way to √number
  for (cpp_int factor{2}; factor <= sqrt; ++factor) {
    // Repeat while factor is in number. For example 8 = 2 * 2 * 2
    while (composite % factor == 0) {
      // Add factor to vector
      factors.emplace_back(factor);
      // Update number accordingly
      composite = composite / factor;
    }
  }

  if (composite > 1)
    factors.emplace_back(composite);
  if (Utilities::isNegative(number))
    factors.emplace_back(-1);
}

void IntegerFactorization::WheelFactorization(const cpp_int &number,
                                              vector<cpp_int> &factors) {

  // Make sure the given vector is empty
  factors.clear();

  // Zero has no prime factors
  if (number == 0)
    throw std::invalid_argument(
        "IntegerFactorization::WheelFactorization: Zero has no prime factors");

  // Make a copy of the number for manipulating
  cpp_int composite = number;

  // Treat all input as positive (we change signs at the end)
  if (Utilities::isNegative(composite))
    composite *= -1;

  // Compute the square root. factor(n) !> √n
  const cpp_int sqrt{boost::multiprecision::sqrt(composite)};

  // Eliminate/add all even factors (this eliminates 50% of numbers to try)
  while (composite % 2 == 0) {
    // Add factor to result vector
    factors.emplace_back(2);
    // Divide by 2
    composite >>= 1;
  }

  // Find odd factors
  for (cpp_int factor = 3; factor <= sqrt; factor += 2) {
    while (composite % factor == 0) {
      factors.emplace_back(factor);
      composite /= factor;
    }
  }
  if (composite > 1)
    factors.emplace_back(composite);

  // Prime factorization is defined only for positives, so this might
  if (Utilities::isNegative(number))
    factors.emplace_back(-1);
}

vector<bool> IntegerFactorization::SieveOfEratosthenes(const cpp_int &n) {
  // Create a vector 'is_prime' to track primality of numbers up to n.
  // Initialize all elements to true.
  vector<bool> is_prime((n + 1).convert_to<long long>(), true);

  // Set 0 and 1 as not prime (false)
  is_prime[0] = false;
  is_prime[1] = false;

  // Iterate through all numbers from 2 to n
  for (long long i{2}; i <= n; ++i) {
    // If i is prime and i^2 is less than or equal to n
    if (is_prime[i] && i * i <= n) {
      // Mark all multiples of i as not prime
      for (long long j{i * i}; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }

  // Return the vector with the primality status of all numbers up to n
  return is_prime;
}
