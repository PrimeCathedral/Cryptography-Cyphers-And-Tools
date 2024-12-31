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

bool isOdd(const cpp_int& number) {
    // If the rightmost bit is one, it is odd
    if (number & 1) return true;
    return false;
}

bool isEven(const cpp_int& number) {
    // If the rightmost bit is one, it is odd
    if (number & 1) return false;
    return true;
}

cpp_int FactorPowersOfTwo(const cpp_int& n) {
    auto s {0};
    auto d {n};

    while (isEven(d)) {
        d >>= 1;
        s++;
    }
    return s;
}


bool Primes::MillerRabinPrimalityTest(const cpp_int& potential_prime, int iterations) {

    // Input n has to be odd and n > 2
    if (isEven(potential_prime) && potential_prime > 2) return false;

    // Variables and containers used:
    auto s {0};
    auto s_copy {};
    cpp_int d {potential_prime - 1};
    cpp_int random_a {0};
    cpp_int x, y;

    // Setup RNG
    // TODO setup so dist is a global variable with upper limit being changed by each method as necessary
    const boost::random::uniform_int_distribution<MP::cpp_int> dist(2, potential_prime - 2);

    // Compute n - 1 = 2^s * d
    while (isEven(d)) {
        d >>= 1;
        s++;
    }

    while (iterations--) {
        // Generate a random number between [e, p - 2]
        random_a = dist(gen);

        // Compute a^d % n
        x = Crypto::ModularArithmetic::modularExponentiation(random_a, d, potential_prime);

        s_copy = s;
        // For each power of 2 (s)
        while (s_copy) {
            // y = x^2 % n
            y = Crypto::ModularArithmetic::modularExponentiation(x, 2, potential_prime);

            if (y == 1 && x != 1 && x != potential_prime - 1) return false;

            x = y;
        }
        if (y != 1) return false;
    }

    return true;
}
