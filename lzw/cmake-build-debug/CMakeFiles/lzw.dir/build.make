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
CMAKE_SOURCE_DIR = C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lzw.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lzw.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lzw.dir/flags.make

CMakeFiles/lzw.dir/main.cpp.obj: CMakeFiles/lzw.dir/flags.make
CMakeFiles/lzw.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lzw.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lzw.dir\main.cpp.obj -c C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\main.cpp

CMakeFiles/lzw.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lzw.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\main.cpp > CMakeFiles\lzw.dir\main.cpp.i

CMakeFiles/lzw.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lzw.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\main.cpp -o CMakeFiles\lzw.dir\main.cpp.s

CMakeFiles/lzw.dir/bitstream.cpp.obj: CMakeFiles/lzw.dir/flags.make
CMakeFiles/lzw.dir/bitstream.cpp.obj: ../bitstream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lzw.dir/bitstream.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lzw.dir\bitstream.cpp.obj -c C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\bitstream.cpp

CMakeFiles/lzw.dir/bitstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lzw.dir/bitstream.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\bitstream.cpp > CMakeFiles\lzw.dir\bitstream.cpp.i

CMakeFiles/lzw.dir/bitstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lzw.dir/bitstream.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\bitstream.cpp -o CMakeFiles\lzw.dir\bitstream.cpp.s

# Object files for target lzw
lzw_OBJECTS = \
"CMakeFiles/lzw.dir/main.cpp.obj" \
"CMakeFiles/lzw.dir/bitstream.cpp.obj"

# External object files for target lzw
lzw_EXTERNAL_OBJECTS =

lzw.exe: CMakeFiles/lzw.dir/main.cpp.obj
lzw.exe: CMakeFiles/lzw.dir/bitstream.cpp.obj
lzw.exe: CMakeFiles/lzw.dir/build.make
lzw.exe: CMakeFiles/lzw.dir/linklibs.rsp
lzw.exe: CMakeFiles/lzw.dir/objects1.rsp
lzw.exe: CMakeFiles/lzw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lzw.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lzw.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lzw.dir/build: lzw.exe

.PHONY : CMakeFiles/lzw.dir/build

CMakeFiles/lzw.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lzw.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lzw.dir/clean

CMakeFiles/lzw.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\cmake-build-debug C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\cmake-build-debug C:\Users\Elisey\OneDrive\Documents\GitHub\school\lzw\cmake-build-debug\CMakeFiles\lzw.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lzw.dir/depend

