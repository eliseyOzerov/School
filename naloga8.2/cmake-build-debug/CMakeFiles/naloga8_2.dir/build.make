# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/naloga8_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/naloga8_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/naloga8_2.dir/flags.make

CMakeFiles/naloga8_2.dir/main.cpp.obj: CMakeFiles/naloga8_2.dir/flags.make
CMakeFiles/naloga8_2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/naloga8_2.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\naloga8_2.dir\main.cpp.obj -c C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2\main.cpp

CMakeFiles/naloga8_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naloga8_2.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2\main.cpp > CMakeFiles\naloga8_2.dir\main.cpp.i

CMakeFiles/naloga8_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naloga8_2.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2\main.cpp -o CMakeFiles\naloga8_2.dir\main.cpp.s

# Object files for target naloga8_2
naloga8_2_OBJECTS = \
"CMakeFiles/naloga8_2.dir/main.cpp.obj"

# External object files for target naloga8_2
naloga8_2_EXTERNAL_OBJECTS =

naloga8_2.exe: CMakeFiles/naloga8_2.dir/main.cpp.obj
naloga8_2.exe: CMakeFiles/naloga8_2.dir/build.make
naloga8_2.exe: CMakeFiles/naloga8_2.dir/linklibs.rsp
naloga8_2.exe: CMakeFiles/naloga8_2.dir/objects1.rsp
naloga8_2.exe: CMakeFiles/naloga8_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable naloga8_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\naloga8_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/naloga8_2.dir/build: naloga8_2.exe

.PHONY : CMakeFiles/naloga8_2.dir/build

CMakeFiles/naloga8_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\naloga8_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/naloga8_2.dir/clean

CMakeFiles/naloga8_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2 C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2 C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2\cmake-build-debug C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2\cmake-build-debug C:\Users\Elisey\OneDrive\Documents\GitHub\school\naloga8.2\cmake-build-debug\CMakeFiles\naloga8_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/naloga8_2.dir/depend

