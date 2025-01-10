//
// Created by Jimmy on 12/22/24.
//

#ifndef MODULAR_ARITHMETIC_H
#define MODULAR_ARITHMETIC_H

#include <boost/multiprecision/cpp_int.hpp>

namespace Crypto {
using boost::multiprecision::cpp_int;
class ModularArithmetic {
public:
  static cpp_int extendedGCD(cpp_int base, const cpp_int &modulus, cpp_int &x,
                             cpp_int &y);
  static cpp_int modularMultiplicativeInverse(const cpp_int &base,
                                              const cpp_int &modulus);
  static cpp_int modularExponentiation(const cpp_int &base,
                                       const cpp_int &power,
                                       const cpp_int &mod);
};

} // namespace Crypto

#endif // MODULAR_ARITHMETIC_H
