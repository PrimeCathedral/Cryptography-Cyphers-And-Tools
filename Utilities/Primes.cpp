//
// Created by Jimmy on 12/30/24.
//

#include "Primes.h"
#include "./Utilities.h"

// TODO remove these defines and find a proper way to do this
#define MA Crypto::ModularArithmetic
#define MP boost::multiprecision

std::random_device rd;  // a seed source for the random number engine
std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

/**
 * Performs the Fermat Primality Test on a given number.
 *
 * The test uses Fermat's Little Theorem to determine if the given number is a prime. It generates a random number
 * (a) in the range [2, potential_prime - 2], and checks:
 * - gcd(potential_prime, a) = 1
 * - a^(potential_prime - 1) % potential_prime = 1
 *
 * @param potential_prime The number to test for primality.
 * @return True if the number is likely prime, false otherwise.
 */
bool Primes::FermatPrimalityTest(const MP::cpp_int& potential_prime) {
    if (potential_prime == 1) return false;
    if (potential_prime <= 3) return true;

    // Setup for Random Number Generator (RNG)
    const boost::random::uniform_int_distribution<MP::cpp_int> dist(2, potential_prime - 2);

    // Generate a random cpp_int between [2, prime - 2] that has uniform distribution
    const cpp_int rand = dist(gen);

    // Check if potential_prime and rand are coprime
    if (boost::integer::gcd(potential_prime, rand) != 1) {
        return false;
    }

    // Check if Fermat's Little Theorem Holds
    if (MA::modularExponentiation(rand, potential_prime - 1, potential_prime) != 1) {
        return false;
    }

    return true;
}

/**
 * Performs the Fermat Primality Test on a given number with multiple iterations for higher accuracy.
 *
* The test uses Fermat's Little Theorem to determine if the given number is a prime. It generates a random number
 * (a) in the range [2, potential_prime - 2], and checks:
 * - gcd(potential_prime, a) = 1
 * - a^(potential_prime - 1) % potential_prime = 1
 * - The process is repeated `times` times, reducing the probability of a false positive with each iteration.
 *
 * @param potential_prime The number to test for primality.
 * @param times The number of iterations to run the test.
 * @return True if the number is likely prime, false otherwise.
 */
bool Primes::FermatPrimalityTest(const MP::cpp_int& potential_prime, int times) {
    if (potential_prime == 1) return false;
    if (potential_prime <= 3) return true;

    // Setup for Random Number Generator (RNG)
    cpp_int rand {};
    const cpp_int limit {potential_prime - 2};
    const boost::random::uniform_int_distribution<MP::cpp_int> dist(2, limit);

    while (times > 0) {

        // Generate a random cpp_int between [2, prime - 2] that has uniform distribution
        rand = dist(gen);

        // Check if potential_prime and rand are coprime
        if (boost::integer::gcd(potential_prime, rand) != 1) {
            return false;
        }

        // Check if Fermat's Little Theorem Holds
        if (MA::modularExponentiation(rand, potential_prime - 1, potential_prime) != 1) {
            return false;
        }

        times--;
    }
    return true;
}

cpp_int FactorPowersOfTwo(const cpp_int& n) {
    auto s {0};
    auto d {n};

    while (Utilities::isEven(d)) {
        d >>= 1;
        s++;
    }
    return s;
}

bool Primes::MillerRabinPrimalityTest(const cpp_int& potential_prime, int iterations) {
    if (potential_prime <= 1) return false;
    if (potential_prime == 2) return true;

    // Input n has to be odd and n > 2
    if (Utilities::isEven(potential_prime) && potential_prime > 2) {
        return false;
    }

    // Initialize variables and RNG setup
    auto s = 0;
    auto s_copy = 0;
    cpp_int d = potential_prime - 1;
    cpp_int random_a = 0;
    cpp_int x = 0, y = 0;

    // Setup RNG (Random Number Generator)
    // TODO: Make `dist` a global variable with an adjustable upper limit
    const boost::random::uniform_int_distribution<MP::cpp_int> dist(2, potential_prime - 2);

    // Decompose n - 1 as 2^s * d (find s and odd d)
    while (Utilities::isEven(d)) {
        d >>= 1;
        s++;
    }

    // Perform the Miller-Rabin test for the given number of iterations
    while (iterations--) {
        // Generate a random number in the range [2, potential_prime - 2]
        random_a = dist(gen);

        // Compute x = random_a^d % potential_prime
        x = Crypto::ModularArithmetic::modularExponentiation(random_a, d, potential_prime);

        // Check through repeated squaring
        s_copy = s;
        while (s_copy--) {
            // Compute y = x^2 % potential_prime
            y = Crypto::ModularArithmetic::modularExponentiation(x, 2, potential_prime);

            // Check for nontrivial square roots of 1 modulo potential_prime
            if (y == 1 && x != 1 && x != potential_prime - 1) {
                return false; // Composite detected
            }

            // Update x for the next iteration
            x = y;
        }

        // If y != 1, the number is composite
        if (y != 1) {
            return false;
        }
    }

    // If all iterations pass, the number is probably prime
    return true;
}
