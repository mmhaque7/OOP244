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
CMAKE_SOURCE_DIR = D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/milestone_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/milestone_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/milestone_1.dir/flags.make

CMakeFiles/milestone_1.dir/ms1.cpp.obj: CMakeFiles/milestone_1.dir/flags.make
CMakeFiles/milestone_1.dir/ms1.cpp.obj: CMakeFiles/milestone_1.dir/includes_CXX.rsp
CMakeFiles/milestone_1.dir/ms1.cpp.obj: ../ms1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/milestone_1.dir/ms1.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\milestone_1.dir\ms1.cpp.obj -c D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\ms1.cpp

CMakeFiles/milestone_1.dir/ms1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone_1.dir/ms1.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\ms1.cpp > CMakeFiles\milestone_1.dir\ms1.cpp.i

CMakeFiles/milestone_1.dir/ms1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone_1.dir/ms1.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\ms1.cpp -o CMakeFiles\milestone_1.dir\ms1.cpp.s

CMakeFiles/milestone_1.dir/Date.cpp.obj: CMakeFiles/milestone_1.dir/flags.make
CMakeFiles/milestone_1.dir/Date.cpp.obj: CMakeFiles/milestone_1.dir/includes_CXX.rsp
CMakeFiles/milestone_1.dir/Date.cpp.obj: ../Date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/milestone_1.dir/Date.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\milestone_1.dir\Date.cpp.obj -c D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\Date.cpp

CMakeFiles/milestone_1.dir/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone_1.dir/Date.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\Date.cpp > CMakeFiles\milestone_1.dir\Date.cpp.i

CMakeFiles/milestone_1.dir/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone_1.dir/Date.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\Date.cpp -o CMakeFiles\milestone_1.dir\Date.cpp.s

# Object files for target milestone_1
milestone_1_OBJECTS = \
"CMakeFiles/milestone_1.dir/ms1.cpp.obj" \
"CMakeFiles/milestone_1.dir/Date.cpp.obj"

# External object files for target milestone_1
milestone_1_EXTERNAL_OBJECTS =

milestone_1.exe: CMakeFiles/milestone_1.dir/ms1.cpp.obj
milestone_1.exe: CMakeFiles/milestone_1.dir/Date.cpp.obj
milestone_1.exe: CMakeFiles/milestone_1.dir/build.make
milestone_1.exe: CMakeFiles/milestone_1.dir/linklibs.rsp
milestone_1.exe: CMakeFiles/milestone_1.dir/objects1.rsp
milestone_1.exe: CMakeFiles/milestone_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable milestone_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\milestone_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/milestone_1.dir/build: milestone_1.exe

.PHONY : CMakeFiles/milestone_1.dir/build

CMakeFiles/milestone_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\milestone_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/milestone_1.dir/clean

CMakeFiles/milestone_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1 D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1 D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\cmake-build-debug D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\cmake-build-debug D:\Seneca\OOP244\OOP244-winter\OOP-Project\MS1\cmake-build-debug\CMakeFiles\milestone_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/milestone_1.dir/depend
