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
CMAKE_SOURCE_DIR = /home/li/NetworkProgramming/BatchWrite

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/NetworkProgramming/BatchWrite/Build

# Include any dependencies generated for this target.
include CMakeFiles/batchwrite.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/batchwrite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/batchwrite.dir/flags.make

CMakeFiles/batchwrite.dir/batchwrite.o: CMakeFiles/batchwrite.dir/flags.make
CMakeFiles/batchwrite.dir/batchwrite.o: ../batchwrite.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/li/NetworkProgramming/BatchWrite/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/batchwrite.dir/batchwrite.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/batchwrite.dir/batchwrite.o   -c /home/li/NetworkProgramming/BatchWrite/batchwrite.c

CMakeFiles/batchwrite.dir/batchwrite.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/batchwrite.dir/batchwrite.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/li/NetworkProgramming/BatchWrite/batchwrite.c > CMakeFiles/batchwrite.dir/batchwrite.i

CMakeFiles/batchwrite.dir/batchwrite.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/batchwrite.dir/batchwrite.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/li/NetworkProgramming/BatchWrite/batchwrite.c -o CMakeFiles/batchwrite.dir/batchwrite.s

# Object files for target batchwrite
batchwrite_OBJECTS = \
"CMakeFiles/batchwrite.dir/batchwrite.o"

# External object files for target batchwrite
batchwrite_EXTERNAL_OBJECTS =

batchwrite: CMakeFiles/batchwrite.dir/batchwrite.o
batchwrite: CMakeFiles/batchwrite.dir/build.make
batchwrite: CMakeFiles/batchwrite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/li/NetworkProgramming/BatchWrite/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable batchwrite"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/batchwrite.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/batchwrite.dir/build: batchwrite

.PHONY : CMakeFiles/batchwrite.dir/build

CMakeFiles/batchwrite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/batchwrite.dir/cmake_clean.cmake
.PHONY : CMakeFiles/batchwrite.dir/clean

CMakeFiles/batchwrite.dir/depend:
	cd /home/li/NetworkProgramming/BatchWrite/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/NetworkProgramming/BatchWrite /home/li/NetworkProgramming/BatchWrite /home/li/NetworkProgramming/BatchWrite/Build /home/li/NetworkProgramming/BatchWrite/Build /home/li/NetworkProgramming/BatchWrite/Build/CMakeFiles/batchwrite.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/batchwrite.dir/depend

