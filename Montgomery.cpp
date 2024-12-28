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

Montgomery::cpp_int Montgomery::montgomeryReduce(const cpp_int &T) const {
    cpp_int m {(T * mod_inv) % R};
    cpp_int t {(T + m * modulus) / R};

    if (t >= modulus) {
        t -= modulus;
    }

    return t;
}
Montgomery::cpp_int Montgomery::multiply(const cpp_int &a, const cpp_int &b) const {
    return montgomeryReduce(a * b);
}