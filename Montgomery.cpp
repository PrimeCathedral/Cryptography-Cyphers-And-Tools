//
// Created by Jimmy on 12/27/24.
//

#include "Montgomery.h"

Montgomery::Montgomery(cpp_int mod) : modulus(std::move(mod)) {
    R = cpp_int(1) << (modulus.backend().size() * 8); // Set R = 2^k where k is bits of n
    R_inv = boost::multiprecision::powm(R, -1, modulus); // R^-1 mod n
    mod_inv = -boost::multiprecision::powm(modulus, -1, R); // -n^-1 mod R
}

Montgomery::cpp_int Montgomery::to_Montgomery(const cpp_int &x) const {
    return (x * R) % modulus;
}

Montgomery::cpp_int Montgomery::from_Montgomery(const cpp_int &x) const {
    return (x * R_inv) % modulus;
}


/**
 *
 * @param T a number in the Montgomery space.
 * @return cpp_int: Montgomery Reduction or REDC output.
 */
// https://cp-algorithms.com/algebra/montgomery_multiplication.html#montgomery-reduction
Montgomery::cpp_int Montgomery::montgomeryReduce(const cpp_int &T) const {
    cpp_int q {(T % R) * mod_inv % R};
    cpp_int a {(T - q * modulus) / R};

    if (a < 0) {
        a += modulus;
    }

    return a;
}
Montgomery::cpp_int Montgomery::multiply(const cpp_int &a, const cpp_int &b) const {
    // a * b := a * b * r^-1 mod n
    return (a * b * R_inv) % modulus;
    // return montgomeryReduce(a * b);
}