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
CMAKE_SOURCE_DIR = /home/li/NetworkProgramming/chap-7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/NetworkProgramming/chap-7/Build

# Include any dependencies generated for this target.
include CMakeFiles/unixdataserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unixdataserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unixdataserver.dir/flags.make

CMakeFiles/unixdataserver.dir/unixdataserver.o: CMakeFiles/unixdataserver.dir/flags.make
CMakeFiles/unixdataserver.dir/unixdataserver.o: ../unixdataserver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/li/NetworkProgramming/chap-7/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/unixdataserver.dir/unixdataserver.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixdataserver.dir/unixdataserver.o   -c /home/li/NetworkProgramming/chap-7/unixdataserver.c

CMakeFiles/unixdataserver.dir/unixdataserver.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixdataserver.dir/unixdataserver.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/li/NetworkProgramming/chap-7/unixdataserver.c > CMakeFiles/unixdataserver.dir/unixdataserver.i

CMakeFiles/unixdataserver.dir/unixdataserver.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixdataserver.dir/unixdataserver.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/li/NetworkProgramming/chap-7/unixdataserver.c -o CMakeFiles/unixdataserver.dir/unixdataserver.s

# Object files for target unixdataserver
unixdataserver_OBJECTS = \
"CMakeFiles/unixdataserver.dir/unixdataserver.o"

# External object files for target unixdataserver
unixdataserver_EXTERNAL_OBJECTS =

unixdataserver: CMakeFiles/unixdataserver.dir/unixdataserver.o
unixdataserver: CMakeFiles/unixdataserver.dir/build.make
unixdataserver: CMakeFiles/unixdataserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/li/NetworkProgramming/chap-7/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable unixdataserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unixdataserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unixdataserver.dir/build: unixdataserver

.PHONY : CMakeFiles/unixdataserver.dir/build

CMakeFiles/unixdataserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unixdataserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unixdataserver.dir/clean

CMakeFiles/unixdataserver.dir/depend:
	cd /home/li/NetworkProgramming/chap-7/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/NetworkProgramming/chap-7 /home/li/NetworkProgramming/chap-7 /home/li/NetworkProgramming/chap-7/Build /home/li/NetworkProgramming/chap-7/Build /home/li/NetworkProgramming/chap-7/Build/CMakeFiles/unixdataserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unixdataserver.dir/depend

