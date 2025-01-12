cmake_minimum_required(VERSION 3.27)
project(Cryptography-Ciphers-And-Tools)

set(CMAKE_CXX_STANDARD 23)

# Enable testing
enable_testing()

# Add the Google Test submodule
add_subdirectory(external/googletest)

# Add the Boost submodule (if not done already)
add_subdirectory(external/boost)

# Add source files to libraries
add_library(ModularArithmetic Utilities/ModularArithmetic.cpp Utilities/ModularArithmetic.hpp)
add_library(Utilities Utilities/Utilities.cpp Utilities/Utilities.hpp)
add_library(Primes Utilities/Primes.cpp Utilities/Primes.hpp)
add_library(IntegerFactorization Utilities/IntegerFactorization.cpp Utilities/IntegerFactorization.hpp)
add_library(DataEncryptionStandard ciphers/des.hpp ciphers/des.cpp)

# Define a common list of libraries to link with (to avoid redundancy)
set(COMMON_LIBS Boost::multiprecision Boost::integer)

# Add executables
add_executable(Crypto main.cpp ciphers/des.cpp ciphers/des.hpp)
add_executable(ModularArithmeticTest tests/ModularArithmeticTest.cpp)
add_executable(PrimesTest tests/PrimesTest.cpp)
add_executable(UtilitiesTest tests/UtilitiesTest.cpp)
add_executable(IntegerFactorizationTest tests/IntegerFactorizationTest.cpp)
add_executable(DESTest tests/DESTest.cpp)

# Link common libraries
target_link_libraries(Crypto Utilities ModularArithmetic Primes DataEncryptionStandard ${COMMON_LIBS})
target_link_libraries(Primes Utilities ModularArithmetic ${COMMON_LIBS})
target_link_libraries(ModularArithmetic ${COMMON_LIBS})
target_link_libraries(Utilities ${COMMON_LIBS})
target_link_libraries(IntegerFactorization Utilities ${COMMON_LIBS})

# Tests - link GTest and GMock to test executables
target_link_libraries(ModularArithmeticTest ModularArithmetic gtest gmock)
target_link_libraries(UtilitiesTest Utilities ${COMMON_LIBS} gtest gmock)
target_link_libraries(PrimesTest Primes ModularArithmetic Utilities ${COMMON_LIBS} gtest gmock)
target_link_libraries(IntegerFactorizationTest IntegerFactorization Utilities ${COMMON_LIBS} gtest gmock)
target_link_libraries(DESTest DataEncryptionStandard gtest gmock)

# Compile definitions
target_compile_definitions(PrimesTest PRIVATE $<$<CONFIG:Debug>:DEBUG_MACRO>)
target_compile_definitions(UtilitiesTest PRIVATE $<$<CONFIG:Debug>:DEBUG_MACRO>)
target_compile_definitions(ModularArithmeticTest PRIVATE $<$<CONFIG:Debug>:DEBUG_MACRO>)
target_compile_definitions(DESTest PRIVATE UNIT_TESTING $<$<CONFIG:Debug>:DEBUG_MACRO>)

# Add the tests to CMake's testing framework
add_test(NAME ModularArithmeticTest COMMAND ModularArithmeticTest)
add_test(NAME PrimesTest COMMAND PrimesTest)
add_test(NAME UtilitiesTest COMMAND UtilitiesTest)
add_test(NAME IntegerFactorizationTest COMMAND IntegerFactorizationTest)
add_test(NAME DESTest COMMAND DESTest)
