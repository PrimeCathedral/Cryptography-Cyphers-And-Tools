# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jimmy/CLionProjects/Crypto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jimmy/CLionProjects/Crypto/build

# Include any dependencies generated for this target.
include CMakeFiles/UtilitiesTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/UtilitiesTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/UtilitiesTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UtilitiesTest.dir/flags.make

CMakeFiles/UtilitiesTest.dir/codegen:
.PHONY : CMakeFiles/UtilitiesTest.dir/codegen

CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.o: CMakeFiles/UtilitiesTest.dir/flags.make
CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.o: /Users/jimmy/CLionProjects/Crypto/tests/UtilitiesTest.cpp
CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.o: CMakeFiles/UtilitiesTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.o -MF CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.o.d -o CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.o -c /Users/jimmy/CLionProjects/Crypto/tests/UtilitiesTest.cpp

CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jimmy/CLionProjects/Crypto/tests/UtilitiesTest.cpp > CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.i

CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jimmy/CLionProjects/Crypto/tests/UtilitiesTest.cpp -o CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.s

# Object files for target UtilitiesTest
UtilitiesTest_OBJECTS = \
"CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.o"

# External object files for target UtilitiesTest
UtilitiesTest_EXTERNAL_OBJECTS =

UtilitiesTest: CMakeFiles/UtilitiesTest.dir/tests/UtilitiesTest.cpp.o
UtilitiesTest: CMakeFiles/UtilitiesTest.dir/build.make
UtilitiesTest: libUtilities.a
UtilitiesTest: lib/libgtest.a
UtilitiesTest: lib/libgmock.a
UtilitiesTest: external/boost/libs/container/libboost_container.a
UtilitiesTest: external/boost/libs/random/libboost_random.a
UtilitiesTest: lib/libgtest.a
UtilitiesTest: CMakeFiles/UtilitiesTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UtilitiesTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UtilitiesTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UtilitiesTest.dir/build: UtilitiesTest
.PHONY : CMakeFiles/UtilitiesTest.dir/build

CMakeFiles/UtilitiesTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UtilitiesTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UtilitiesTest.dir/clean

CMakeFiles/UtilitiesTest.dir/depend:
	cd /Users/jimmy/CLionProjects/Crypto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build/CMakeFiles/UtilitiesTest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/UtilitiesTest.dir/depend

