//
// Created by Jimmy on 12/27/24.
//

#ifndef MONTGOMERY_H
#define MONTGOMERY_H

#include <boost/multiprecision/cpp_int.hpp>

class Montgomery {
public:
    using cpp_int = boost::multiprecision::cpp_int;
private:
    cpp_int modulus;    // n
    cpp_int R;          // Radix
    cpp_int R_inv;      // R^-1 mod n
    cpp_int mod_inv;    // -n^-1 mod R
public:

    // Constructor takes a large enough n that is prime (or at least coprime)
    explicit Montgomery(cpp_int  mod);

    [[nodiscard]] cpp_int to_Montgomery(const cpp_int& x) const;
    [[nodiscard]] cpp_int from_Montgomery(const cpp_int& x) const;
    [[nodiscard]] cpp_int multiply(const cpp_int& a, const cpp_int& b) const;

private:
    [[nodiscard]] cpp_int montgomeryReduce(const cpp_int& T) const;
};



#endif //MONTGOMERY_H
