//
// Created by Jimmy on 12/30/24.
//

#ifndef PRIMES_H
#define PRIMES_H

#include <boost/multiprecision/cpp_int.hpp>

class Primes {

public:
    static bool FermatPrimalityTest(const boost::multiprecision::cpp_int& potential_prime);
    static bool FermatPrimalityTest(const boost::multiprecision::cpp_int& potential_prime, int times);

};



#endif //PRIMES_H
