# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sanggu/nP_Term

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sanggu/nP_Term/build

# Include any dependencies generated for this target.
include CMakeFiles/s.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/s.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/s.dir/flags.make

CMakeFiles/s.dir/s.c.o: CMakeFiles/s.dir/flags.make
CMakeFiles/s.dir/s.c.o: ../s.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sanggu/nP_Term/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/s.dir/s.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/s.dir/s.c.o   -c /home/sanggu/nP_Term/s.c

CMakeFiles/s.dir/s.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/s.dir/s.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sanggu/nP_Term/s.c > CMakeFiles/s.dir/s.c.i

CMakeFiles/s.dir/s.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/s.dir/s.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sanggu/nP_Term/s.c -o CMakeFiles/s.dir/s.c.s

CMakeFiles/s.dir/s.c.o.requires:

.PHONY : CMakeFiles/s.dir/s.c.o.requires

CMakeFiles/s.dir/s.c.o.provides: CMakeFiles/s.dir/s.c.o.requires
	$(MAKE) -f CMakeFiles/s.dir/build.make CMakeFiles/s.dir/s.c.o.provides.build
.PHONY : CMakeFiles/s.dir/s.c.o.provides

CMakeFiles/s.dir/s.c.o.provides.build: CMakeFiles/s.dir/s.c.o


# Object files for target s
s_OBJECTS = \
"CMakeFiles/s.dir/s.c.o"

# External object files for target s
s_EXTERNAL_OBJECTS =

s : CMakeFiles/s.dir/s.c.o
s : CMakeFiles/s.dir/build.make
s : CMakeFiles/s.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sanggu/nP_Term/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable s"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/s.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/s.dir/build: s

.PHONY : CMakeFiles/s.dir/build

CMakeFiles/s.dir/requires: CMakeFiles/s.dir/s.c.o.requires

.PHONY : CMakeFiles/s.dir/requires

CMakeFiles/s.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/s.dir/cmake_clean.cmake
.PHONY : CMakeFiles/s.dir/clean

CMakeFiles/s.dir/depend:
	cd /home/sanggu/nP_Term/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sanggu/nP_Term /home/sanggu/nP_Term /home/sanggu/nP_Term/build /home/sanggu/nP_Term/build /home/sanggu/nP_Term/build/CMakeFiles/s.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/s.dir/depend

