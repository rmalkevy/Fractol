# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/CLionProjects/Fractol_

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/CLionProjects/Fractol_/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fractol_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fractol_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fractol_.dir/flags.make

CMakeFiles/Fractol_.dir/main.c.o: CMakeFiles/Fractol_.dir/flags.make
CMakeFiles/Fractol_.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/CLionProjects/Fractol_/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Fractol_.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fractol_.dir/main.c.o   -c /Users/mac/CLionProjects/Fractol_/main.c

CMakeFiles/Fractol_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fractol_.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mac/CLionProjects/Fractol_/main.c > CMakeFiles/Fractol_.dir/main.c.i

CMakeFiles/Fractol_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fractol_.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mac/CLionProjects/Fractol_/main.c -o CMakeFiles/Fractol_.dir/main.c.s

CMakeFiles/Fractol_.dir/main.c.o.requires:

.PHONY : CMakeFiles/Fractol_.dir/main.c.o.requires

CMakeFiles/Fractol_.dir/main.c.o.provides: CMakeFiles/Fractol_.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Fractol_.dir/build.make CMakeFiles/Fractol_.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Fractol_.dir/main.c.o.provides

CMakeFiles/Fractol_.dir/main.c.o.provides.build: CMakeFiles/Fractol_.dir/main.c.o


# Object files for target Fractol_
Fractol__OBJECTS = \
"CMakeFiles/Fractol_.dir/main.c.o"

# External object files for target Fractol_
Fractol__EXTERNAL_OBJECTS =

Fractol_: CMakeFiles/Fractol_.dir/main.c.o
Fractol_: CMakeFiles/Fractol_.dir/build.make
Fractol_: CMakeFiles/Fractol_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mac/CLionProjects/Fractol_/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Fractol_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Fractol_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fractol_.dir/build: Fractol_

.PHONY : CMakeFiles/Fractol_.dir/build

CMakeFiles/Fractol_.dir/requires: CMakeFiles/Fractol_.dir/main.c.o.requires

.PHONY : CMakeFiles/Fractol_.dir/requires

CMakeFiles/Fractol_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Fractol_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Fractol_.dir/clean

CMakeFiles/Fractol_.dir/depend:
	cd /Users/mac/CLionProjects/Fractol_/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/CLionProjects/Fractol_ /Users/mac/CLionProjects/Fractol_ /Users/mac/CLionProjects/Fractol_/cmake-build-debug /Users/mac/CLionProjects/Fractol_/cmake-build-debug /Users/mac/CLionProjects/Fractol_/cmake-build-debug/CMakeFiles/Fractol_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fractol_.dir/depend

