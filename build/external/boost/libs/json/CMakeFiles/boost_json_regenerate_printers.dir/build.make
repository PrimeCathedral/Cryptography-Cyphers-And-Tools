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

# Utility rule file for boost_json_regenerate_printers.

# Include any custom commands dependencies for this target.
include external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/compiler_depend.make

# Include the progress variables for this target.
include external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/progress.make

external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers: external/boost/libs/json/include/boost/json/detail/gdb_printers.hpp

external/boost/libs/json/include/boost/json/detail/gdb_printers.hpp: /Users/jimmy/CLionProjects/Crypto/external/boost/libs/json/src/boost_json_gdb_printers.py
external/boost/libs/json/include/boost/json/detail/gdb_printers.hpp: /Users/jimmy/CLionProjects/Crypto/external/boost/libs/json/pretty_printers/generate-gdb-header.py
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Regenerating include/boost/json/detail/gdb_printers.hpp"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/json && /opt/homebrew/Frameworks/Python.framework/Versions/3.13/bin/python3.13 /Users/jimmy/CLionProjects/Crypto/external/boost/libs/json/pretty_printers/generate-gdb-header.py /Users/jimmy/CLionProjects/Crypto/external/boost/libs/json/src/boost_json_gdb_printers.py /Users/jimmy/CLionProjects/Crypto/external/boost/libs/json/include/boost/json/detail/gdb_printers.hpp --header-guard=BOOST_JSON_DETAIL_GDB_PRINTERS_HPP --disable-macro=

external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/codegen:
.PHONY : external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/codegen

boost_json_regenerate_printers: external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers
boost_json_regenerate_printers: external/boost/libs/json/include/boost/json/detail/gdb_printers.hpp
boost_json_regenerate_printers: external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/build.make
.PHONY : boost_json_regenerate_printers

# Rule to build all files generated by this target.
external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/build: boost_json_regenerate_printers
.PHONY : external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/build

external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/clean:
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/json && $(CMAKE_COMMAND) -P CMakeFiles/boost_json_regenerate_printers.dir/cmake_clean.cmake
.PHONY : external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/clean

external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/depend:
	cd /Users/jimmy/CLionProjects/Crypto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto/external/boost/libs/json /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/json /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : external/boost/libs/json/CMakeFiles/boost_json_regenerate_printers.dir/depend

