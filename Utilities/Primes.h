//
// Created by Jimmy on 12/30/24.
//

#ifndef PRIMES_H
#define PRIMES_H
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random/random_number_generator.hpp>
#include "ModularArithmetic.h"
#include "./Utilities.h"

class Primes {

public:
    static bool FermatPrimalityTest(const cpp_int& potential_prime);
    static bool FermatPrimalityTest(const cpp_int& potential_prime, int times);
    static bool MillerRabinPrimalityTest(const cpp_int& potential_prime);
    static bool MillerRabinPrimalityTest(const cpp_int& potential_prime, int iterations);

};



#endif //PRIMES_H
