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
CMAKE_SOURCE_DIR = /home/li/NetworkProgramming/KeepAlive

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/NetworkProgramming/KeepAlive/Build

# Include any dependencies generated for this target.
include CMakeFiles/pingclient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pingclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pingclient.dir/flags.make

CMakeFiles/pingclient.dir/pingclient.o: CMakeFiles/pingclient.dir/flags.make
CMakeFiles/pingclient.dir/pingclient.o: ../pingclient.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/li/NetworkProgramming/KeepAlive/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pingclient.dir/pingclient.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pingclient.dir/pingclient.o   -c /home/li/NetworkProgramming/KeepAlive/pingclient.c

CMakeFiles/pingclient.dir/pingclient.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pingclient.dir/pingclient.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/li/NetworkProgramming/KeepAlive/pingclient.c > CMakeFiles/pingclient.dir/pingclient.i

CMakeFiles/pingclient.dir/pingclient.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pingclient.dir/pingclient.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/li/NetworkProgramming/KeepAlive/pingclient.c -o CMakeFiles/pingclient.dir/pingclient.s

# Object files for target pingclient
pingclient_OBJECTS = \
"CMakeFiles/pingclient.dir/pingclient.o"

# External object files for target pingclient
pingclient_EXTERNAL_OBJECTS =

pingclient: CMakeFiles/pingclient.dir/pingclient.o
pingclient: CMakeFiles/pingclient.dir/build.make
pingclient: CMakeFiles/pingclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/li/NetworkProgramming/KeepAlive/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pingclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pingclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pingclient.dir/build: pingclient

.PHONY : CMakeFiles/pingclient.dir/build

CMakeFiles/pingclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pingclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pingclient.dir/clean

CMakeFiles/pingclient.dir/depend:
	cd /home/li/NetworkProgramming/KeepAlive/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/NetworkProgramming/KeepAlive /home/li/NetworkProgramming/KeepAlive /home/li/NetworkProgramming/KeepAlive/Build /home/li/NetworkProgramming/KeepAlive/Build /home/li/NetworkProgramming/KeepAlive/Build/CMakeFiles/pingclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pingclient.dir/depend
