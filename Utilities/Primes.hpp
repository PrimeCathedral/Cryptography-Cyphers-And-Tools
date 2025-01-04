//
// Created by Jimmy on 12/30/24.
//

#ifndef PRIMES_H
#define PRIMES_H

#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random/random_number_generator.hpp>
#include "ModularArithmetic.hpp"
#include "Utilities.hpp"

#define ITERATIONS 40

class Primes {
    using cpp_int = boost::multiprecision::cpp_int;
public:
    static cpp_int generatePrime(const int& numBits);
    static bool FermatPrimalityTest(const cpp_int& candidate);
    static bool FermatPrimalityTest(const cpp_int& potential_prime, int times);
    static bool MillerRabinPrimalityTest(const cpp_int& candidate);
    static bool MillerRabinPrimalityTest(const cpp_int& potential_prime, int iterations);
    // TODO: define expanded versions of Primality Tests to work with custom iterations
};



#endif //PRIMES_H
