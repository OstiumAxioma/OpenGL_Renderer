# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ostiumaxioma/Development/cmake_vscode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ostiumaxioma/Development/cmake_vscode/build

# Include any dependencies generated for this target.
include CMakeFiles/cmake_vscode.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cmake_vscode.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cmake_vscode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmake_vscode.dir/flags.make

CMakeFiles/cmake_vscode.dir/main.cpp.o: CMakeFiles/cmake_vscode.dir/flags.make
CMakeFiles/cmake_vscode.dir/main.cpp.o: /Users/ostiumaxioma/Development/cmake_vscode/main.cpp
CMakeFiles/cmake_vscode.dir/main.cpp.o: CMakeFiles/cmake_vscode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ostiumaxioma/Development/cmake_vscode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmake_vscode.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cmake_vscode.dir/main.cpp.o -MF CMakeFiles/cmake_vscode.dir/main.cpp.o.d -o CMakeFiles/cmake_vscode.dir/main.cpp.o -c /Users/ostiumaxioma/Development/cmake_vscode/main.cpp

CMakeFiles/cmake_vscode.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cmake_vscode.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ostiumaxioma/Development/cmake_vscode/main.cpp > CMakeFiles/cmake_vscode.dir/main.cpp.i

CMakeFiles/cmake_vscode.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cmake_vscode.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ostiumaxioma/Development/cmake_vscode/main.cpp -o CMakeFiles/cmake_vscode.dir/main.cpp.s

# Object files for target cmake_vscode
cmake_vscode_OBJECTS = \
"CMakeFiles/cmake_vscode.dir/main.cpp.o"

# External object files for target cmake_vscode
cmake_vscode_EXTERNAL_OBJECTS =

cmake_vscode: CMakeFiles/cmake_vscode.dir/main.cpp.o
cmake_vscode: CMakeFiles/cmake_vscode.dir/build.make
cmake_vscode: /usr/local/lib/libglfw3.a
cmake_vscode: libglad.a
cmake_vscode: CMakeFiles/cmake_vscode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ostiumaxioma/Development/cmake_vscode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cmake_vscode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmake_vscode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmake_vscode.dir/build: cmake_vscode
.PHONY : CMakeFiles/cmake_vscode.dir/build

CMakeFiles/cmake_vscode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmake_vscode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmake_vscode.dir/clean

CMakeFiles/cmake_vscode.dir/depend:
	cd /Users/ostiumaxioma/Development/cmake_vscode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ostiumaxioma/Development/cmake_vscode /Users/ostiumaxioma/Development/cmake_vscode /Users/ostiumaxioma/Development/cmake_vscode/build /Users/ostiumaxioma/Development/cmake_vscode/build /Users/ostiumaxioma/Development/cmake_vscode/build/CMakeFiles/cmake_vscode.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cmake_vscode.dir/depend

