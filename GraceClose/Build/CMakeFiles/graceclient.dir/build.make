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
CMAKE_SOURCE_DIR = /home/li/NetworkProgramming/GraceClose

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/NetworkProgramming/GraceClose/Build

# Include any dependencies generated for this target.
include CMakeFiles/graceclient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graceclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graceclient.dir/flags.make

CMakeFiles/graceclient.dir/graceclient.o: CMakeFiles/graceclient.dir/flags.make
CMakeFiles/graceclient.dir/graceclient.o: ../graceclient.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/li/NetworkProgramming/GraceClose/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/graceclient.dir/graceclient.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/graceclient.dir/graceclient.o   -c /home/li/NetworkProgramming/GraceClose/graceclient.c

CMakeFiles/graceclient.dir/graceclient.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/graceclient.dir/graceclient.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/li/NetworkProgramming/GraceClose/graceclient.c > CMakeFiles/graceclient.dir/graceclient.i

CMakeFiles/graceclient.dir/graceclient.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/graceclient.dir/graceclient.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/li/NetworkProgramming/GraceClose/graceclient.c -o CMakeFiles/graceclient.dir/graceclient.s

# Object files for target graceclient
graceclient_OBJECTS = \
"CMakeFiles/graceclient.dir/graceclient.o"

# External object files for target graceclient
graceclient_EXTERNAL_OBJECTS =

graceclient: CMakeFiles/graceclient.dir/graceclient.o
graceclient: CMakeFiles/graceclient.dir/build.make
graceclient: CMakeFiles/graceclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/li/NetworkProgramming/GraceClose/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable graceclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graceclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graceclient.dir/build: graceclient

.PHONY : CMakeFiles/graceclient.dir/build

CMakeFiles/graceclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graceclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graceclient.dir/clean

CMakeFiles/graceclient.dir/depend:
	cd /home/li/NetworkProgramming/GraceClose/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/NetworkProgramming/GraceClose /home/li/NetworkProgramming/GraceClose /home/li/NetworkProgramming/GraceClose/Build /home/li/NetworkProgramming/GraceClose/Build /home/li/NetworkProgramming/GraceClose/Build/CMakeFiles/graceclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graceclient.dir/depend

