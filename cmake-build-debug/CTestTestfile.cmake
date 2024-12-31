# CMake generated Testfile for 
# Source directory: /Users/jimmy/CLionProjects/Crypto
# Build directory: /Users/jimmy/CLionProjects/Crypto/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[ModularArithmeticTest]=] "/Users/jimmy/CLionProjects/Crypto/cmake-build-debug/ModularArithmeticTest")
set_tests_properties([=[ModularArithmeticTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;32;add_test;/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;0;")
add_test([=[PrimesTest]=] "/Users/jimmy/CLionProjects/Crypto/cmake-build-debug/PrimesTest")
set_tests_properties([=[PrimesTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;33;add_test;/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;0;")
subdirs("external/boost")
subdirs("external/googletest")
