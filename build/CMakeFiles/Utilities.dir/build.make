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
include CMakeFiles/Utilities.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Utilities.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Utilities.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Utilities.dir/flags.make

CMakeFiles/Utilities.dir/codegen:
.PHONY : CMakeFiles/Utilities.dir/codegen

CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.o: CMakeFiles/Utilities.dir/flags.make
CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.o: /Users/jimmy/CLionProjects/Crypto/Utilities/Utilities.cpp
CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.o: CMakeFiles/Utilities.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.o -MF CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.o.d -o CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.o -c /Users/jimmy/CLionProjects/Crypto/Utilities/Utilities.cpp

CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jimmy/CLionProjects/Crypto/Utilities/Utilities.cpp > CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.i

CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jimmy/CLionProjects/Crypto/Utilities/Utilities.cpp -o CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.s

# Object files for target Utilities
Utilities_OBJECTS = \
"CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.o"

# External object files for target Utilities
Utilities_EXTERNAL_OBJECTS =

libUtilities.a: CMakeFiles/Utilities.dir/Utilities/Utilities.cpp.o
libUtilities.a: CMakeFiles/Utilities.dir/build.make
libUtilities.a: CMakeFiles/Utilities.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUtilities.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Utilities.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Utilities.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Utilities.dir/build: libUtilities.a
.PHONY : CMakeFiles/Utilities.dir/build

CMakeFiles/Utilities.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Utilities.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Utilities.dir/clean

CMakeFiles/Utilities.dir/depend:
	cd /Users/jimmy/CLionProjects/Crypto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build/CMakeFiles/Utilities.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Utilities.dir/depend

