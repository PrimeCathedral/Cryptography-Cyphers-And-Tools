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
include external/boost/libs/context/CMakeFiles/boost_context.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/boost/libs/context/CMakeFiles/boost_context.dir/compiler_depend.make

# Include the progress variables for this target.
include external/boost/libs/context/CMakeFiles/boost_context.dir/progress.make

# Include the compile flags for this target's objects.
include external/boost/libs/context/CMakeFiles/boost_context.dir/flags.make

external/boost/libs/context/CMakeFiles/boost_context.dir/codegen:
.PHONY : external/boost/libs/context/CMakeFiles/boost_context.dir/codegen

external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.o: external/boost/libs/context/CMakeFiles/boost_context.dir/flags.make
external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.o: /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/make_arm64_aapcs_macho_gas.S
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ASM object external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.o"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.o -c /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/make_arm64_aapcs_macho_gas.S

external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing ASM source to CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.i"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/make_arm64_aapcs_macho_gas.S > CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.i

external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling ASM source to assembly CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.s"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/make_arm64_aapcs_macho_gas.S -o CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.s

external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.o: external/boost/libs/context/CMakeFiles/boost_context.dir/flags.make
external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.o: /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/jump_arm64_aapcs_macho_gas.S
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building ASM object external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.o"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.o -c /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/jump_arm64_aapcs_macho_gas.S

external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing ASM source to CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.i"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/jump_arm64_aapcs_macho_gas.S > CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.i

external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling ASM source to assembly CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.s"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/jump_arm64_aapcs_macho_gas.S -o CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.s

external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.o: external/boost/libs/context/CMakeFiles/boost_context.dir/flags.make
external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.o: /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/ontop_arm64_aapcs_macho_gas.S
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building ASM object external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.o"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.o -c /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/ontop_arm64_aapcs_macho_gas.S

external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing ASM source to CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.i"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/ontop_arm64_aapcs_macho_gas.S > CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.i

external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling ASM source to assembly CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.s"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/asm/ontop_arm64_aapcs_macho_gas.S -o CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.s

external/boost/libs/context/CMakeFiles/boost_context.dir/src/fcontext.cpp.o: external/boost/libs/context/CMakeFiles/boost_context.dir/flags.make
external/boost/libs/context/CMakeFiles/boost_context.dir/src/fcontext.cpp.o: /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/fcontext.cpp
external/boost/libs/context/CMakeFiles/boost_context.dir/src/fcontext.cpp.o: external/boost/libs/context/CMakeFiles/boost_context.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object external/boost/libs/context/CMakeFiles/boost_context.dir/src/fcontext.cpp.o"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/boost/libs/context/CMakeFiles/boost_context.dir/src/fcontext.cpp.o -MF CMakeFiles/boost_context.dir/src/fcontext.cpp.o.d -o CMakeFiles/boost_context.dir/src/fcontext.cpp.o -c /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/fcontext.cpp

external/boost/libs/context/CMakeFiles/boost_context.dir/src/fcontext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/boost_context.dir/src/fcontext.cpp.i"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/fcontext.cpp > CMakeFiles/boost_context.dir/src/fcontext.cpp.i

external/boost/libs/context/CMakeFiles/boost_context.dir/src/fcontext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/boost_context.dir/src/fcontext.cpp.s"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/fcontext.cpp -o CMakeFiles/boost_context.dir/src/fcontext.cpp.s

external/boost/libs/context/CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.o: external/boost/libs/context/CMakeFiles/boost_context.dir/flags.make
external/boost/libs/context/CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.o: /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/posix/stack_traits.cpp
external/boost/libs/context/CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.o: external/boost/libs/context/CMakeFiles/boost_context.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object external/boost/libs/context/CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.o"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/boost/libs/context/CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.o -MF CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.o.d -o CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.o -c /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/posix/stack_traits.cpp

external/boost/libs/context/CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.i"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/posix/stack_traits.cpp > CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.i

external/boost/libs/context/CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.s"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context/src/posix/stack_traits.cpp -o CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.s

# Object files for target boost_context
boost_context_OBJECTS = \
"CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.o" \
"CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.o" \
"CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.o" \
"CMakeFiles/boost_context.dir/src/fcontext.cpp.o" \
"CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.o"

# External object files for target boost_context
boost_context_EXTERNAL_OBJECTS =

external/boost/libs/context/libboost_context.a: external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/make_arm64_aapcs_macho_gas.S.o
external/boost/libs/context/libboost_context.a: external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/jump_arm64_aapcs_macho_gas.S.o
external/boost/libs/context/libboost_context.a: external/boost/libs/context/CMakeFiles/boost_context.dir/src/asm/ontop_arm64_aapcs_macho_gas.S.o
external/boost/libs/context/libboost_context.a: external/boost/libs/context/CMakeFiles/boost_context.dir/src/fcontext.cpp.o
external/boost/libs/context/libboost_context.a: external/boost/libs/context/CMakeFiles/boost_context.dir/src/posix/stack_traits.cpp.o
external/boost/libs/context/libboost_context.a: external/boost/libs/context/CMakeFiles/boost_context.dir/build.make
external/boost/libs/context/libboost_context.a: external/boost/libs/context/CMakeFiles/boost_context.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jimmy/CLionProjects/Crypto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libboost_context.a"
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && $(CMAKE_COMMAND) -P CMakeFiles/boost_context.dir/cmake_clean_target.cmake
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_context.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/boost/libs/context/CMakeFiles/boost_context.dir/build: external/boost/libs/context/libboost_context.a
.PHONY : external/boost/libs/context/CMakeFiles/boost_context.dir/build

external/boost/libs/context/CMakeFiles/boost_context.dir/clean:
	cd /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context && $(CMAKE_COMMAND) -P CMakeFiles/boost_context.dir/cmake_clean.cmake
.PHONY : external/boost/libs/context/CMakeFiles/boost_context.dir/clean

external/boost/libs/context/CMakeFiles/boost_context.dir/depend:
	cd /Users/jimmy/CLionProjects/Crypto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jimmy/CLionProjects/Crypto /Users/jimmy/CLionProjects/Crypto/external/boost/libs/context /Users/jimmy/CLionProjects/Crypto/build /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context /Users/jimmy/CLionProjects/Crypto/build/external/boost/libs/context/CMakeFiles/boost_context.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : external/boost/libs/context/CMakeFiles/boost_context.dir/depend
