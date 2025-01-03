//
// Created by Jimmy on 12/30/24.
//

#include "Primes.h"
#include "Utilities.h"

// TODO: Find a better way to manage this macro
#define MA Crypto::ModularArithmetic

// Random number generator setup
std::random_device rd;  // Seed source for the random number engine
std::mt19937 gen(rd()); // Mersenne Twister engine seeded with rd()

/**
 * Determines the number of iterations to use for primality testing.
 * If the candidate number is smaller than a predefined threshold (ITERATIONS),
 * the number of iterations is adjusted to half the candidate.
 *
 * @param num The candidate number.
 * @return The number of iterations to use for the test.
 */
int defineIterations(const cpp_int& num) {
    if (ITERATIONS >= num) {
        return (num >> 1).convert_to<int>();
    }
    return ITERATIONS;
}

/**
 * Factors out powers of 2 from a given number.
 * Decomposes n - 1 into 2^s * d where d is odd.
 *
 * @param n The input number.
 * @return The odd component after factoring out powers of 2.
 */
cpp_int FactorPowersOfTwo(const cpp_int& n) {
    auto s = 0;
    auto d = n;

    while (Utilities::isEven(d)) {
        d >>= 1;
        s++;
    }
    return s;
}

/**
 * Performs the Fermat Primality Test on a candidate number.
 * Uses Fermat's Little Theorem to check if a number is likely prime.
 *
 * @param candidate The number to test for primality.
 * @return True if the number is likely prime, false otherwise.
 */
bool Primes::FermatPrimalityTest(const cpp_int& candidate) {
    if (candidate == 1) return false;
    if (candidate <= 3) return true;

    // Determine number of iterations
    int iterations = defineIterations(candidate);

    // Setup for random number generator (RNG)
    cpp_int rand {};
    const cpp_int limit = candidate - 2;
    const boost::random::uniform_int_distribution<cpp_int> dist(2, limit);

    while (iterations--) {
        // Generate a random number between [2, candidate - 2]
        rand = dist(gen);

        // Check if candidate and rand are coprime
        if (boost::integer::gcd(candidate, rand) != 1) {
            return false;
        }

        // Verify Fermat's Little Theorem
        if (MA::modularExponentiation(rand, candidate - 1, candidate) != 1) {
            return false;
        }
    }
    return true;
}

/**
 * Performs the Miller-Rabin Primality Test on a candidate number.
 * This test is probabilistic and provides higher accuracy than the Fermat Primality Test.
 *
 * @param candidate The number to test for primality.
 * @return True if the number is likely prime, false otherwise.
 */
bool Primes::MillerRabinPrimalityTest(const cpp_int& candidate) {
    if (candidate <= 1) return false;
    if (candidate == 2) return true;

    // Determine number of iterations
    int iterations = defineIterations(candidate);

    // Ensure candidate is odd and greater than 2
    if (Utilities::isEven(candidate) && candidate > 2) {
        return false;
    }

    // Decompose candidate - 1 into 2^s * d
    cpp_int d = candidate - 1;
    int s = 0;
    while (Utilities::isEven(d)) {
        d >>= 1;
        s++;
    }

    // Setup RNG
    const boost::random::uniform_int_distribution<cpp_int> dist(2, candidate - 2);

    // Perform Miller-Rabin test
    while (iterations--) {
        cpp_int random_a = dist(gen);
        cpp_int x = MA::modularExponentiation(random_a, d, candidate);

        // Check through repeated squaring
        for (int i = 0; i < s; ++i) {
            cpp_int y = MA::modularExponentiation(x, 2, candidate);

            if (y == 1 && x != 1 && x != candidate - 1) {
                return false; // Composite detected
            }

            x = y;
        }

        if (x != 1) {
            return false;
        }
    }

    return true;
}

/**
 * Generates a prime number with the specified number of bits.
 * Uses the Miller-Rabin and Fermat Primality Tests for validation.
 *
 * @param numBits The number of bits for the prime number.
 * @return A prime number with the specified number of bits.
 * @throws std::runtime_error If numBits < 2 (primes cannot be smaller than 2 bits).
 */
cpp_int Primes::generatePrime(const int& numBits) {

    // TODO: Fix bug that prevents generating primes of bit size = 2

    if (numBits < 3) {
        throw std::runtime_error("Number of bits must be at least 3.");
    }

    // Calculate bit boundaries
    const cpp_int lower_bound = cpp_int(1) << (numBits - 1); // 2^(numBits - 1)
    const cpp_int upper_bound = (cpp_int(1) << numBits) - 1; // 2^numBits - 1
    const boost::random::uniform_int_distribution<cpp_int> dist(lower_bound, upper_bound);

    // Generate candidate primes
    cpp_int candidate;
    do {
        candidate = dist(gen);

        // Ensure candidate is odd
        if (Utilities::isEven(candidate)) {
            candidate += 1;
        }
    } while (!(MillerRabinPrimalityTest(candidate) && FermatPrimalityTest(candidate)));

    return candidate;
}
