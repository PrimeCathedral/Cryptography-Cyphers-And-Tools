cmake_minimum_required(VERSION 3.27)
project(Crypto)

set(CMAKE_CXX_STANDARD 23)

# Add the main Crypto executable (target, source files)
add_executable(Crypto main.cpp Utilities.cpp
        Utilities/ModularArithmetic.cpp
        Utilities/ModularArithmetic.h)
add_executable(test_example tests/test_example.cpp)
add_executable(test_utilities tests/test_utilities.cpp)
add_executable(test_modular_arithmetic tests/test_modular_arithmetic.cpp)

# Enable testing
enable_testing()

# Add directories
include_directories(external/boost) # boost library
include_directories(external/googletest/googletest/include) # Gtest libraries

# Add the Google Test submodule
add_subdirectory(external/boost)
add_subdirectory(external/googletest)

# Add your source files to a library
add_library(Utilities utilities.cpp utilities.h)
add_library(ModularArithmetic Utilities/ModularArithmetic.cpp Utilities/ModularArithmetic.h)

# Link Google Test, Google Mock, and utilities library to the test executables
target_link_libraries(test_example gtest gmock)
target_link_libraries(Utilities Boost::multiprecision)
target_link_libraries(ModularArithmetic Boost::multiprecision)
target_link_libraries(test_utilities Utilities gtest gmock Boost::multiprecision)
target_link_libraries(test_modular_arithmetic ModularArithmetic gtest gmock  Boost::multiprecision)

# Add the tests to CMake's testing framework
add_test(NAME SampleTest COMMAND test_example)
add_test(NAME TestUtilities COMMAND test_utilities)
add_test(NAME TestModularArithmetic COMMAND test_modular_arithmetic)


