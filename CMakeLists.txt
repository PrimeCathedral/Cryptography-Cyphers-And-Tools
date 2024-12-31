cmake_minimum_required(VERSION 3.27)
project(Cryptography-Ciphers-And-Tools)

set(CMAKE_CXX_STANDARD 23)

# Add the executables (target, source files)
add_executable(ModularArithmeticTest tests/ModularArithmeticTest.cpp)
add_executable(PrimesTest tests/PrimesTest.cpp)

# Enable testing
enable_testing()

# Add directories
#include_directories(external/boost) # boost library
include_directories(external/googletest/googletest/include) # Gtest libraries

# Add the Google Test submodule
add_subdirectory(external/boost)
add_subdirectory(external/googletest)

# Add your source files to a library
add_library(ModularArithmetic Utilities/ModularArithmetic.cpp Utilities/ModularArithmetic.h)
add_library(Primes Utilities/Primes.cpp Utilities/Primes.h)

# Link Google Test, Google Mock, and utilities library to the test executables
target_link_libraries(ModularArithmetic Boost::multiprecision)
target_link_libraries(ModularArithmeticTest ModularArithmetic gtest gmock)
target_link_libraries(Primes ModularArithmetic Boost::multiprecision)
target_link_libraries(PrimesTest Primes ModularArithmetic Boost::multiprecision Boost::integer gtest gmock)

# Add the tests to CMake's testing framework
add_test(NAME ModularArithmeticTest COMMAND ModularArithmeticTest)
add_test(NAME PrimesTest COMMAND PrimesTest)