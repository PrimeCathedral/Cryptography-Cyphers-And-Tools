cmake_minimum_required(VERSION 3.27)
project(Cryptography-Ciphers-And-Tools)

set(CMAKE_CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# # Add the Google Test submodule
# add_subdirectory(external/googletest)

# Add the Boost submodule (if not done already)
add_subdirectory(external/boost)

# Add source files to libraries
add_library(ModularArithmetic Utilities/ModularArithmetic.cpp Utilities/ModularArithmetic.hpp)
add_library(Utilities Utilities/Utilities.cpp Utilities/Utilities.hpp)
add_library(Primes Utilities/Primes.cpp Utilities/Primes.hpp)
add_library(IntegerFactorization Utilities/IntegerFactorization.cpp Utilities/IntegerFactorization.hpp)
add_library(DataEncryptionStandard ciphers/des.hpp ciphers/des.cpp Utilities/bytearray.h)
add_library(ByteArray ./Utilities/bytearray.h ./Utilities/bytearray.cpp Utilities/bytearray.cpp)

# Define a common list of libraries to link with (to avoid redundancy)
set(COMMON_LIBS Boost::multiprecision Boost::integer)

# Add executables
add_executable(Crypto main.cpp ciphers/des.cpp ciphers/des.hpp Utilities/bytearray.h)
add_executable(ModularArithmeticTest tests/ModularArithmeticTest.cpp)
add_executable(PrimesTest tests/PrimesTest.cpp)
add_executable(UtilitiesTest tests/UtilitiesTest.cpp)
add_executable(IntegerFactorizationTest tests/IntegerFactorizationTest.cpp)
add_executable(DESTest tests/DESTest.cpp Utilities/bytearray.h)
add_executable(ByteArrayTest tests/ByteArrayTest.cpp)

# Link common libraries
target_link_libraries(Crypto Utilities ModularArithmetic Primes DataEncryptionStandard ${COMMON_LIBS})
target_link_libraries(Primes Utilities ModularArithmetic ${COMMON_LIBS})
target_link_libraries(ModularArithmetic ${COMMON_LIBS})
target_link_libraries(Utilities ${COMMON_LIBS})
target_link_libraries(IntegerFactorization Utilities ${COMMON_LIBS})
target_link_libraries(DataEncryptionStandard ByteArray ${COMMON_LIBS})
target_link_libraries(ByteArray ${COMMON_LIBS})

# Tests - link GTest and GMock to test executables
target_link_libraries(ModularArithmeticTest ModularArithmetic GTest::gtest_main)
target_link_libraries(UtilitiesTest Utilities ${COMMON_LIBS} GTest::gtest_main)
target_link_libraries(PrimesTest Primes ModularArithmetic Utilities ${COMMON_LIBS} GTest::gtest_main)
target_link_libraries(IntegerFactorizationTest IntegerFactorization Utilities ${COMMON_LIBS} GTest::gtest_main)
target_link_libraries(DESTest DataEncryptionStandard GTest::gtest_main ByteArray)
target_link_libraries(ByteArrayTest ByteArray GTest::gtest_main)

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


enable_testing()

include(GoogleTest)
gtest_discover_tests(ModularArithmeticTest UtilitiesTest PrimesTest IntegerFactorizationTest DESTest)