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
CMAKE_SOURCE_DIR = /home/li/NetworkProgramming/UDPConnect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/NetworkProgramming/UDPConnect/Build

# Include any dependencies generated for this target.
include CMakeFiles/udpconnectserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udpconnectserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udpconnectserver.dir/flags.make

CMakeFiles/udpconnectserver.dir/udpconnectserver.o: CMakeFiles/udpconnectserver.dir/flags.make
CMakeFiles/udpconnectserver.dir/udpconnectserver.o: ../udpconnectserver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/li/NetworkProgramming/UDPConnect/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/udpconnectserver.dir/udpconnectserver.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/udpconnectserver.dir/udpconnectserver.o   -c /home/li/NetworkProgramming/UDPConnect/udpconnectserver.c

CMakeFiles/udpconnectserver.dir/udpconnectserver.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udpconnectserver.dir/udpconnectserver.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/li/NetworkProgramming/UDPConnect/udpconnectserver.c > CMakeFiles/udpconnectserver.dir/udpconnectserver.i

CMakeFiles/udpconnectserver.dir/udpconnectserver.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udpconnectserver.dir/udpconnectserver.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/li/NetworkProgramming/UDPConnect/udpconnectserver.c -o CMakeFiles/udpconnectserver.dir/udpconnectserver.s

# Object files for target udpconnectserver
udpconnectserver_OBJECTS = \
"CMakeFiles/udpconnectserver.dir/udpconnectserver.o"

# External object files for target udpconnectserver
udpconnectserver_EXTERNAL_OBJECTS =

udpconnectserver: CMakeFiles/udpconnectserver.dir/udpconnectserver.o
udpconnectserver: CMakeFiles/udpconnectserver.dir/build.make
udpconnectserver: CMakeFiles/udpconnectserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/li/NetworkProgramming/UDPConnect/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable udpconnectserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udpconnectserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udpconnectserver.dir/build: udpconnectserver

.PHONY : CMakeFiles/udpconnectserver.dir/build

CMakeFiles/udpconnectserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udpconnectserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udpconnectserver.dir/clean

CMakeFiles/udpconnectserver.dir/depend:
	cd /home/li/NetworkProgramming/UDPConnect/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/NetworkProgramming/UDPConnect /home/li/NetworkProgramming/UDPConnect /home/li/NetworkProgramming/UDPConnect/Build /home/li/NetworkProgramming/UDPConnect/Build /home/li/NetworkProgramming/UDPConnect/Build/CMakeFiles/udpconnectserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udpconnectserver.dir/depend

