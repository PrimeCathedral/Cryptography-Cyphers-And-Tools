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
include CMakeFiles/Primes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Primes.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Primes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Primes.dir/flags.make

CMakeFiles/Primes.dir/codegen:
.PHONY : CMakeFiles/Primes.dir/codegen

CMakeFiles/Primes.dir/Utilities/Primes.cpp.o: CMakeFiles/Primes.dir/flags.make
CMakeFiles/Primes.dir/Utilities/Primes.cpp.o: /Users/jimmy/CLionProjects/Crypto/Utilities/Primes.cpp
CMakeFiles/Primes.dir/Utilities/Primes.cpp.o: CMakeFiles/Primes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Primes.dir/Utilities/Primes.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Primes.dir/Utilities/Primes.cpp.o -MF CMakeFiles/Primes.dir/Utilities/Primes.cpp.o.d -o CMakeFiles/Primes.dir/Utilities/Primes.cpp.o -c /Users/jimmy/CLionProjects/Crypto/Utilities/Primes.cpp

CMakeFiles/Primes.dir/Utilities/Primes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Primes.dir/Utilities/Primes.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jimmy/CLionProjects/Crypto/Utilities/Primes.cpp > CMakeFiles/Primes.dir/Utilities/Primes.cpp.i

CMakeFiles/Primes.dir/Utilities/Primes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Primes.dir/Utilities/Primes.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jimmy/CLionProjects/Crypto/Utilities/Primes.cpp -o CMakeFiles/Primes.dir/Utilities/Primes.cpp.s

# Object files for target Primes
Primes_OBJECTS = \
"CMakeFiles/Primes.dir/Utilities/Primes.cpp.o"

# External object files for target Primes
Primes_EXTERNAL_OBJECTS =

libPrimes.a: CMakeFiles/Primes.dir/Utilities/Primes.cpp.o
libPrimes.a: CMakeFiles/Primes.dir/build.make
libPrimes.a: CMakeFiles/Primes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPrimes.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Primes.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Primes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Primes.dir/build: libPrimes.a
.PHONY : CMakeFiles/Primes.dir/build

CMakeFiles/Primes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Primes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Primes.dir/clean

CMakeFiles/Primes.dir/depend:
	cd /Users/jimmy/CLionProjects/Crypto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build/CMakeFiles/Primes.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Primes.dir/depend
