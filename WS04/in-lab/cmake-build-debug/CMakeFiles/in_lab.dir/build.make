# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/in_lab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/in_lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/in_lab.dir/flags.make

CMakeFiles/in_lab.dir/Traveler.cpp.obj: CMakeFiles/in_lab.dir/flags.make
CMakeFiles/in_lab.dir/Traveler.cpp.obj: CMakeFiles/in_lab.dir/includes_CXX.rsp
CMakeFiles/in_lab.dir/Traveler.cpp.obj: ../Traveler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/in_lab.dir/Traveler.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\in_lab.dir\Traveler.cpp.obj -c D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\Traveler.cpp

CMakeFiles/in_lab.dir/Traveler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/in_lab.dir/Traveler.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\Traveler.cpp > CMakeFiles\in_lab.dir\Traveler.cpp.i

CMakeFiles/in_lab.dir/Traveler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/in_lab.dir/Traveler.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\Traveler.cpp -o CMakeFiles\in_lab.dir\Traveler.cpp.s

CMakeFiles/in_lab.dir/w4_in_lab.cpp.obj: CMakeFiles/in_lab.dir/flags.make
CMakeFiles/in_lab.dir/w4_in_lab.cpp.obj: CMakeFiles/in_lab.dir/includes_CXX.rsp
CMakeFiles/in_lab.dir/w4_in_lab.cpp.obj: ../w4_in_lab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/in_lab.dir/w4_in_lab.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\in_lab.dir\w4_in_lab.cpp.obj -c D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\w4_in_lab.cpp

CMakeFiles/in_lab.dir/w4_in_lab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/in_lab.dir/w4_in_lab.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\w4_in_lab.cpp > CMakeFiles\in_lab.dir\w4_in_lab.cpp.i

CMakeFiles/in_lab.dir/w4_in_lab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/in_lab.dir/w4_in_lab.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\w4_in_lab.cpp -o CMakeFiles\in_lab.dir\w4_in_lab.cpp.s

# Object files for target in_lab
in_lab_OBJECTS = \
"CMakeFiles/in_lab.dir/Traveler.cpp.obj" \
"CMakeFiles/in_lab.dir/w4_in_lab.cpp.obj"

# External object files for target in_lab
in_lab_EXTERNAL_OBJECTS =

in_lab.exe: CMakeFiles/in_lab.dir/Traveler.cpp.obj
in_lab.exe: CMakeFiles/in_lab.dir/w4_in_lab.cpp.obj
in_lab.exe: CMakeFiles/in_lab.dir/build.make
in_lab.exe: CMakeFiles/in_lab.dir/linklibs.rsp
in_lab.exe: CMakeFiles/in_lab.dir/objects1.rsp
in_lab.exe: CMakeFiles/in_lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable in_lab.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\in_lab.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/in_lab.dir/build: in_lab.exe

.PHONY : CMakeFiles/in_lab.dir/build

CMakeFiles/in_lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\in_lab.dir\cmake_clean.cmake
.PHONY : CMakeFiles/in_lab.dir/clean

CMakeFiles/in_lab.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\cmake-build-debug D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\cmake-build-debug D:\Seneca\OOP244\OOP244-winter\OOP-Workshops\WS04\in-lab\cmake-build-debug\CMakeFiles\in_lab.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/in_lab.dir/depend

