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
include CMakeFiles/boost_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/boost_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/boost_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boost_test.dir/flags.make

CMakeFiles/boost_test.dir/codegen:
.PHONY : CMakeFiles/boost_test.dir/codegen

CMakeFiles/boost_test.dir/boost_test.cpp.o: CMakeFiles/boost_test.dir/flags.make
CMakeFiles/boost_test.dir/boost_test.cpp.o: /Users/jimmy/CLionProjects/Crypto/boost_test.cpp
CMakeFiles/boost_test.dir/boost_test.cpp.o: CMakeFiles/boost_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boost_test.dir/boost_test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/boost_test.dir/boost_test.cpp.o -MF CMakeFiles/boost_test.dir/boost_test.cpp.o.d -o CMakeFiles/boost_test.dir/boost_test.cpp.o -c /Users/jimmy/CLionProjects/Crypto/boost_test.cpp

CMakeFiles/boost_test.dir/boost_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/boost_test.dir/boost_test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jimmy/CLionProjects/Crypto/boost_test.cpp > CMakeFiles/boost_test.dir/boost_test.cpp.i

CMakeFiles/boost_test.dir/boost_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/boost_test.dir/boost_test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jimmy/CLionProjects/Crypto/boost_test.cpp -o CMakeFiles/boost_test.dir/boost_test.cpp.s

# Object files for target boost_test
boost_test_OBJECTS = \
"CMakeFiles/boost_test.dir/boost_test.cpp.o"

# External object files for target boost_test
boost_test_EXTERNAL_OBJECTS =

boost_test: CMakeFiles/boost_test.dir/boost_test.cpp.o
boost_test: CMakeFiles/boost_test.dir/build.make
boost_test: CMakeFiles/boost_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boost_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boost_test.dir/build: boost_test
.PHONY : CMakeFiles/boost_test.dir/build

CMakeFiles/boost_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boost_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boost_test.dir/clean

CMakeFiles/boost_test.dir/depend:
	cd /Users/jimmy/CLionProjects/Crypto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build/CMakeFiles/boost_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/boost_test.dir/depend
