//
// Created by Jimmy on 12/30/24.
//

#include "Primes.h"

#include "ModularArithmetic.h"

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
