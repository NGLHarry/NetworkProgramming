# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/li/NetworkProgramming/Fork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/NetworkProgramming/Fork/Build

# Include any dependencies generated for this target.
include CMakeFiles/fork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fork.dir/flags.make

CMakeFiles/fork.dir/fork.o: CMakeFiles/fork.dir/flags.make
CMakeFiles/fork.dir/fork.o: ../fork.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/li/NetworkProgramming/Fork/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fork.dir/fork.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fork.dir/fork.o   -c /home/li/NetworkProgramming/Fork/fork.c

CMakeFiles/fork.dir/fork.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fork.dir/fork.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/li/NetworkProgramming/Fork/fork.c > CMakeFiles/fork.dir/fork.i

CMakeFiles/fork.dir/fork.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fork.dir/fork.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/li/NetworkProgramming/Fork/fork.c -o CMakeFiles/fork.dir/fork.s

# Object files for target fork
fork_OBJECTS = \
"CMakeFiles/fork.dir/fork.o"

# External object files for target fork
fork_EXTERNAL_OBJECTS =

fork: CMakeFiles/fork.dir/fork.o
fork: CMakeFiles/fork.dir/build.make
fork: CMakeFiles/fork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/li/NetworkProgramming/Fork/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fork.dir/build: fork

.PHONY : CMakeFiles/fork.dir/build

CMakeFiles/fork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fork.dir/clean

CMakeFiles/fork.dir/depend:
	cd /home/li/NetworkProgramming/Fork/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/NetworkProgramming/Fork /home/li/NetworkProgramming/Fork /home/li/NetworkProgramming/Fork/Build /home/li/NetworkProgramming/Fork/Build /home/li/NetworkProgramming/Fork/Build/CMakeFiles/fork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fork.dir/depend

