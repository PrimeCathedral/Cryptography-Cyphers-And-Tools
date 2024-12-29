//
// Created by Jimmy on 12/28/24.
//

#include "ModularArithmetic.h"
#include <stdexcept>

ModularArithmetic::ModularArithmetic(const cpp_int& mod) : mod(mod){
    if (mod == 0) throw std::runtime_error("Modular Arithmetic Math Error: Attempted to divide by Zero.\n");
}

boost::multiprecision::cpp_int ModularArithmetic::add(const cpp_int &a, const cpp_int &b) {
  return (a % mod + b % mod) % mod;
}

boost::multiprecision::cpp_int ModularArithmetic::substract(const cpp_int &a, const cpp_int &b) {

}

boost::multiprecision::cpp_int ModularArithmetic::multiply(const cpp_int &a, const cpp_int &b) {

}

boost::multiprecision::cpp_int ModularArithmetic::divide(const cpp_int &a, const cpp_int &b) {

 }// TODO implement modular division
boost::multiprecision::cpp_int ModularArithmetic::power(const cpp_int &a, const cpp_int &b) {

}

boost::multiprecision::cpp_int ModularArithmetic::inverse(const cpp_int &a) {

 }// Find modular inverse