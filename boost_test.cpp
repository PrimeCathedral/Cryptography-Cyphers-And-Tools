//
// Created by Jimmy on 12/22/24.
//
#include <boost/version.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

int main() {
    std::cout << "Boost version: " << BOOST_VERSION / 100000 << "."
              << BOOST_VERSION / 100 % 1000 << "."
              << BOOST_VERSION % 100 << std::endl;

    using namespace boost::multiprecision;

    cpp_int num1 = 123456789012345678901234567890_cpp;
    cpp_int num2 = 987654321098765432109876543210_cpp;

    cpp_int sum = num1 + num2;
    cpp_int product = num1 * num2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}
