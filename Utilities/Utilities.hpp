//
// Created by Jimmy on 12/31/24.
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

class Utilities {
public:
  static bool isOdd(const cpp_int &number);
  static bool isEven(const cpp_int &number);
  static bool isPositive(const cpp_int &number);
  static bool isNegative(const cpp_int &number);
  static bool isNotPositive(const cpp_int &number);
  static bool isNotNegative(const cpp_int &number);
  static cpp_int binaryExponentiation(const cpp_int &base,
                                      const cpp_int &power);
};

#endif // UTILITIES_H
