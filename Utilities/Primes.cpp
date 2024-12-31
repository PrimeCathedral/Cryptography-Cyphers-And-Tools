//
// Created by Jimmy on 12/30/24.
//

#include "Primes.h"
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/integer/common_factor.hpp>
#include <boost/random/random_number_generator.hpp>

#include "ModularArithmetic.h"
#define MA Crypto::ModularArithmetic
#define MP boost::multiprecision


std::random_device rd;  // a seed source for the random number engine
std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

bool Primes::FermatPrimalityTest(const MP::cpp_int& potential_prime) {
    if (potential_prime == 1) return false;
    if (potential_prime <= 3) return true;

    // Setup for Random Number Generator (RNG)
    const boost::random::uniform_int_distribution<MP::cpp_int> dist(2, potential_prime - 2);

    // Generate a random cpp_int between [2, prime - 2] that has uniform distribution
    cpp_int rand = dist(gen);
    // Check if prime and "a" are coprime
    if (boost::integer::gcd(potential_prime, rand) != 1) {
        return false;
    }
    // Check if Fermat's Little Theorem Holds
    if (MA::modularExponentiation(rand, potential_prime - 1, potential_prime) != 1) {
        return false;
    }

    return true;
}

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

        // Check if prime and "a" are coprime
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