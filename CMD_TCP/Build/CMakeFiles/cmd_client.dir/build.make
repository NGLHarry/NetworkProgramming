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
CMAKE_SOURCE_DIR = /home/li/NetworkProgramming/CMD_TCP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/NetworkProgramming/CMD_TCP/Build

# Include any dependencies generated for this target.
include CMakeFiles/cmd_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cmd_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmd_client.dir/flags.make

CMakeFiles/cmd_client.dir/cmd_client.o: CMakeFiles/cmd_client.dir/flags.make
CMakeFiles/cmd_client.dir/cmd_client.o: ../cmd_client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/li/NetworkProgramming/CMD_TCP/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cmd_client.dir/cmd_client.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cmd_client.dir/cmd_client.o   -c /home/li/NetworkProgramming/CMD_TCP/cmd_client.c

CMakeFiles/cmd_client.dir/cmd_client.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cmd_client.dir/cmd_client.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/li/NetworkProgramming/CMD_TCP/cmd_client.c > CMakeFiles/cmd_client.dir/cmd_client.i

CMakeFiles/cmd_client.dir/cmd_client.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cmd_client.dir/cmd_client.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/li/NetworkProgramming/CMD_TCP/cmd_client.c -o CMakeFiles/cmd_client.dir/cmd_client.s

# Object files for target cmd_client
cmd_client_OBJECTS = \
"CMakeFiles/cmd_client.dir/cmd_client.o"

# External object files for target cmd_client
cmd_client_EXTERNAL_OBJECTS =

cmd_client: CMakeFiles/cmd_client.dir/cmd_client.o
cmd_client: CMakeFiles/cmd_client.dir/build.make
cmd_client: CMakeFiles/cmd_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/li/NetworkProgramming/CMD_TCP/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cmd_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmd_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmd_client.dir/build: cmd_client

.PHONY : CMakeFiles/cmd_client.dir/build

CMakeFiles/cmd_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmd_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmd_client.dir/clean

CMakeFiles/cmd_client.dir/depend:
	cd /home/li/NetworkProgramming/CMD_TCP/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/NetworkProgramming/CMD_TCP /home/li/NetworkProgramming/CMD_TCP /home/li/NetworkProgramming/CMD_TCP/Build /home/li/NetworkProgramming/CMD_TCP/Build /home/li/NetworkProgramming/CMD_TCP/Build/CMakeFiles/cmd_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cmd_client.dir/depend

