cmake_minimum_required(VERSION 3.27)
project(Cryptography-Ciphers-And-Tools)

set(CMAKE_CXX_STANDARD 23)

# Add the executables (target, source files)
add_executable(Crypto main.cpp
        ciphers/des.cpp
        ciphers/des.hpp)
add_executable(ModularArithmeticTest tests/ModularArithmeticTest.cpp)
add_executable(PrimesTest tests/PrimesTest.cpp)
add_executable(UtilitiesTest tests/UtilitiesTest.cpp)
add_executable(IntegerFactorizationTest tests/IntegerFactorizationTest.cpp)

# Enable testing
enable_testing()

# Add directories
#include_directories(external/boost) # boost library
include_directories(external/googletest/googletest/include) # Gtest libraries

# Add the Google Test submodule
add_subdirectory(external/boost)
add_subdirectory(external/googletest)

# Add your source files to a library
add_library(ModularArithmetic Utilities/ModularArithmetic.cpp Utilities/ModularArithmetic.hpp)
add_library(Utilities Utilities/Utilities.cpp Utilities/Utilities.hpp)
add_library(Primes Utilities/Primes.cpp Utilities/Primes.hpp)
add_library(IntegerFactorization Utilities/IntegerFactorization.cpp Utilities/IntegerFactorization.hpp)

# Link Google Test, Google Mock, and utilities library to the test executables
target_link_libraries(Crypto Utilities ModularArithmetic Primes Boost::multiprecision Boost::integer)
target_link_libraries(Primes Utilities ModularArithmetic Boost::multiprecision)
target_link_libraries(ModularArithmetic Boost::multiprecision)
target_link_libraries(Utilities Boost::multiprecision)
target_link_libraries(IntegerFactorization Utilities Boost::multiprecision)

# Tests
target_link_libraries(ModularArithmeticTest ModularArithmetic gtest gmock)
target_link_libraries(UtilitiesTest Utilities Boost::multiprecision gtest gmock)
target_link_libraries(PrimesTest Primes ModularArithmetic Utilities Boost::multiprecision Boost::integer gtest gmock)
target_link_libraries(IntegerFactorizationTest IntegerFactorization  Utilities Boost::multiprecision gtest gmock)

# Compile definitions
target_compile_definitions(PrimesTest PRIVATE $<$<CONFIG:Debug>:DEBUG_MACRO>)
target_compile_definitions(UtilitiesTest PRIVATE $<$<CONFIG:Debug>:DEBUG_MACRO>)
target_compile_definitions(ModularArithmeticTest PRIVATE $<$<CONFIG:Debug>:DEBUG_MACRO>)

# Add the tests to CMake's testing framework
add_test(NAME ModularArithmeticTest COMMAND ModularArithmeticTest)
add_test(NAME PrimesTest COMMAND PrimesTest)
add_test(NAME UtilitiesTest COMMAND UtilitiesTest)
add_test(NAME IntegerFactorizationTest COMMAND IntegerFactorizationTest)

