//
// Created by Jimmy on 1/3/25.
//

#ifndef INTEGER_FACTORIZATION_HPP
#define INTEGER_FACTORIZATION_HPP

#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

using boost::multiprecision::cpp_int;
using std::vector;

class IntegerFactorization {
  // TODO: Include better comments for these function
  // TODO: Maybe move them to a namespace instead of in class static??
public:
  // Uses trial division to compute al prime factors of a given number
  static void TrialDivision(const cpp_int &number, vector<cpp_int> &factors);

  // Uses wheel factorization to return all prime factors of a given number
  static void WheelFactorization(const cpp_int &number,
                                 vector<cpp_int> &factors);

  // Determines prime numbers up to n
  static vector<bool> SieveOfEratosthenes(const cpp_int &n);
};

#endif // INTEGER_FACTORIZATION_HPP
