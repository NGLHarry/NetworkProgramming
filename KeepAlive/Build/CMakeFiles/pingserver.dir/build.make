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
include CMakeFiles/pingserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pingserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pingserver.dir/flags.make

CMakeFiles/pingserver.dir/pingserver.o: CMakeFiles/pingserver.dir/flags.make
CMakeFiles/pingserver.dir/pingserver.o: ../pingserver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/li/NetworkProgramming/KeepAlive/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pingserver.dir/pingserver.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pingserver.dir/pingserver.o   -c /home/li/NetworkProgramming/KeepAlive/pingserver.c

CMakeFiles/pingserver.dir/pingserver.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pingserver.dir/pingserver.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/li/NetworkProgramming/KeepAlive/pingserver.c > CMakeFiles/pingserver.dir/pingserver.i

CMakeFiles/pingserver.dir/pingserver.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pingserver.dir/pingserver.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/li/NetworkProgramming/KeepAlive/pingserver.c -o CMakeFiles/pingserver.dir/pingserver.s

# Object files for target pingserver
pingserver_OBJECTS = \
"CMakeFiles/pingserver.dir/pingserver.o"

# External object files for target pingserver
pingserver_EXTERNAL_OBJECTS =

pingserver: CMakeFiles/pingserver.dir/pingserver.o
pingserver: CMakeFiles/pingserver.dir/build.make
pingserver: CMakeFiles/pingserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/li/NetworkProgramming/KeepAlive/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pingserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pingserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pingserver.dir/build: pingserver

.PHONY : CMakeFiles/pingserver.dir/build

CMakeFiles/pingserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pingserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pingserver.dir/clean

CMakeFiles/pingserver.dir/depend:
	cd /home/li/NetworkProgramming/KeepAlive/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/NetworkProgramming/KeepAlive /home/li/NetworkProgramming/KeepAlive /home/li/NetworkProgramming/KeepAlive/Build /home/li/NetworkProgramming/KeepAlive/Build /home/li/NetworkProgramming/KeepAlive/Build/CMakeFiles/pingserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pingserver.dir/depend
