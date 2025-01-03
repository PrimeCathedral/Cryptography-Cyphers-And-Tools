# CMake generated Testfile for 
# Source directory: /Users/jimmy/CLionProjects/Crypto
# Build directory: /Users/jimmy/CLionProjects/Crypto/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[ModularArithmeticTest]=] "/Users/jimmy/CLionProjects/Crypto/build/ModularArithmeticTest")
set_tests_properties([=[ModularArithmeticTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;46;add_test;/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;0;")
add_test([=[PrimesTest]=] "/Users/jimmy/CLionProjects/Crypto/build/PrimesTest")
set_tests_properties([=[PrimesTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;47;add_test;/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;0;")
add_test([=[UtilitiesTest]=] "/Users/jimmy/CLionProjects/Crypto/build/UtilitiesTest")
set_tests_properties([=[UtilitiesTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;48;add_test;/Users/jimmy/CLionProjects/Crypto/CMakeLists.txt;0;")
subdirs("external/boost")
subdirs("external/googletest")
