# CMake generated Testfile for 
# Source directory: /Users/jimmy/CLionProjects/Crypto
# Build directory: /Users/jimmy/CLionProjects/Crypto/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[TestModularArithmetic]=] "/Users/jimmy/CLionProjects/Crypto/cmake-build-debug/ModularArithmeticTest")
set_tests_properties([=[TestModularArithmetic]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;28;add_test;/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;0;")
subdirs("external/boost")
subdirs("external/googletest")
