# CMake generated Testfile for 
# Source directory: /Users/jimmy/CLionProjects/Crypto
# Build directory: /Users/jimmy/CLionProjects/Crypto/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[SampleTest]=] "/Users/jimmy/CLionProjects/Crypto/build/test_example")
set_tests_properties([=[SampleTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;31;add_test;/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;0;")
add_test([=[TestUtilities]=] "/Users/jimmy/CLionProjects/Crypto/build/test_utilities")
set_tests_properties([=[TestUtilities]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;32;add_test;/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;0;")
subdirs("external/googletest")
subdirs("external/boost")
