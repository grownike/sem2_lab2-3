# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/grownike/clion/CLion-2021.2.1/clion-2021.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/grownike/clion/CLion-2021.2.1/clion-2021.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/grownike/sem2labs/lab2v3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/grownike/sem2labs/lab2v3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab2v3.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lab2v3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2v3.dir/flags.make

CMakeFiles/lab2v3.dir/main.cpp.o: CMakeFiles/lab2v3.dir/flags.make
CMakeFiles/lab2v3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grownike/sem2labs/lab2v3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab2v3.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab2v3.dir/main.cpp.o -c /home/grownike/sem2labs/lab2v3/main.cpp

CMakeFiles/lab2v3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2v3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grownike/sem2labs/lab2v3/main.cpp > CMakeFiles/lab2v3.dir/main.cpp.i

CMakeFiles/lab2v3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2v3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grownike/sem2labs/lab2v3/main.cpp -o CMakeFiles/lab2v3.dir/main.cpp.s

# Object files for target lab2v3
lab2v3_OBJECTS = \
"CMakeFiles/lab2v3.dir/main.cpp.o"

# External object files for target lab2v3
lab2v3_EXTERNAL_OBJECTS =

lab2v3: CMakeFiles/lab2v3.dir/main.cpp.o
lab2v3: CMakeFiles/lab2v3.dir/build.make
lab2v3: CMakeFiles/lab2v3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grownike/sem2labs/lab2v3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab2v3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2v3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2v3.dir/build: lab2v3
.PHONY : CMakeFiles/lab2v3.dir/build

CMakeFiles/lab2v3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab2v3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab2v3.dir/clean

CMakeFiles/lab2v3.dir/depend:
	cd /home/grownike/sem2labs/lab2v3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grownike/sem2labs/lab2v3 /home/grownike/sem2labs/lab2v3 /home/grownike/sem2labs/lab2v3/cmake-build-debug /home/grownike/sem2labs/lab2v3/cmake-build-debug /home/grownike/sem2labs/lab2v3/cmake-build-debug/CMakeFiles/lab2v3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab2v3.dir/depend
