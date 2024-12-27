cmake_minimum_required(VERSION 3.27)
project(Crypto)

set(CMAKE_CXX_STANDARD 23)

# Add the main Crypto executable (target, source files)
add_executable(Crypto main.cpp Utilities.cpp)
add_executable(test_example tests/test_example.cpp)
add_executable(utilities tests/test_utilities.cpp utilities.cpp)
add_executable(boost_test boost_test.cpp)

# Enable testing
enable_testing()

# Add directories
include_directories(external/googletest/googletest/include) # Gtest libraries
include_directories(external/boost) # boost library

# Add the Google Test submodule
add_subdirectory(external/googletest)
add_subdirectory(external/boost) # Might need to rework this line along with 17. Works for now

## Add your source files to a library
#add_library(utilities STATIC Utilities.cpp)

# Link Google Test, Google Mock, and utilities library to the test executables
target_link_libraries(test_example gtest gmock)
target_link_libraries(test_utilities gtest gmock utilities)
target_link_libraries(boost_test Boost::multiprecision)
target_link_libraries(utilities Boost::multiprecision)

# Add the tests to CMake's testing framework
add_test(NAME SampleTest COMMAND test_example)
add_test(NAME TestUtilities COMMAND test_utilities)
