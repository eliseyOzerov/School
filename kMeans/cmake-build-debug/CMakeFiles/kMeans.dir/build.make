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
CMAKE_SOURCE_DIR = C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/kMeans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kMeans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kMeans.dir/flags.make

CMakeFiles/kMeans.dir/main.cpp.obj: CMakeFiles/kMeans.dir/flags.make
CMakeFiles/kMeans.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kMeans.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\kMeans.dir\main.cpp.obj -c C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\main.cpp

CMakeFiles/kMeans.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kMeans.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\main.cpp > CMakeFiles\kMeans.dir\main.cpp.i

CMakeFiles/kMeans.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kMeans.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\main.cpp -o CMakeFiles\kMeans.dir\main.cpp.s

CMakeFiles/kMeans.dir/kMeans.cpp.obj: CMakeFiles/kMeans.dir/flags.make
CMakeFiles/kMeans.dir/kMeans.cpp.obj: ../kMeans.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kMeans.dir/kMeans.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\kMeans.dir\kMeans.cpp.obj -c C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\kMeans.cpp

CMakeFiles/kMeans.dir/kMeans.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kMeans.dir/kMeans.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\kMeans.cpp > CMakeFiles\kMeans.dir\kMeans.cpp.i

CMakeFiles/kMeans.dir/kMeans.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kMeans.dir/kMeans.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\kMeans.cpp -o CMakeFiles\kMeans.dir\kMeans.cpp.s

# Object files for target kMeans
kMeans_OBJECTS = \
"CMakeFiles/kMeans.dir/main.cpp.obj" \
"CMakeFiles/kMeans.dir/kMeans.cpp.obj"

# External object files for target kMeans
kMeans_EXTERNAL_OBJECTS =

kMeans.exe: CMakeFiles/kMeans.dir/main.cpp.obj
kMeans.exe: CMakeFiles/kMeans.dir/kMeans.cpp.obj
kMeans.exe: CMakeFiles/kMeans.dir/build.make
kMeans.exe: CMakeFiles/kMeans.dir/linklibs.rsp
kMeans.exe: CMakeFiles/kMeans.dir/objects1.rsp
kMeans.exe: CMakeFiles/kMeans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable kMeans.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\kMeans.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kMeans.dir/build: kMeans.exe

.PHONY : CMakeFiles/kMeans.dir/build

CMakeFiles/kMeans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\kMeans.dir\cmake_clean.cmake
.PHONY : CMakeFiles/kMeans.dir/clean

CMakeFiles/kMeans.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\cmake-build-debug C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\cmake-build-debug C:\Users\Elisey\OneDrive\Documents\GitHub\school\kMeans\cmake-build-debug\CMakeFiles\kMeans.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kMeans.dir/depend

