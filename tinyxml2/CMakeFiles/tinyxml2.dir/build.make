# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.6.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.6.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/admos/AlgorithmPractice/tinyxml2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/admos/AlgorithmPractice/tinyxml2

# Include any dependencies generated for this target.
include CMakeFiles/tinyxml2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tinyxml2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tinyxml2.dir/flags.make

CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o: CMakeFiles/tinyxml2.dir/flags.make
CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o: tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admos/AlgorithmPractice/tinyxml2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o -c /Users/admos/AlgorithmPractice/tinyxml2/tinyxml2.cpp

CMakeFiles/tinyxml2.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyxml2.dir/tinyxml2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admos/AlgorithmPractice/tinyxml2/tinyxml2.cpp > CMakeFiles/tinyxml2.dir/tinyxml2.cpp.i

CMakeFiles/tinyxml2.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyxml2.dir/tinyxml2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admos/AlgorithmPractice/tinyxml2/tinyxml2.cpp -o CMakeFiles/tinyxml2.dir/tinyxml2.cpp.s

CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o.requires:

.PHONY : CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o.requires

CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o.provides: CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o.requires
	$(MAKE) -f CMakeFiles/tinyxml2.dir/build.make CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o.provides.build
.PHONY : CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o.provides

CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o.provides.build: CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o


# Object files for target tinyxml2
tinyxml2_OBJECTS = \
"CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o"

# External object files for target tinyxml2
tinyxml2_EXTERNAL_OBJECTS =

libtinyxml2.4.0.1.dylib: CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o
libtinyxml2.4.0.1.dylib: CMakeFiles/tinyxml2.dir/build.make
libtinyxml2.4.0.1.dylib: CMakeFiles/tinyxml2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/admos/AlgorithmPractice/tinyxml2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libtinyxml2.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tinyxml2.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libtinyxml2.4.0.1.dylib libtinyxml2.4.dylib libtinyxml2.dylib

libtinyxml2.4.dylib: libtinyxml2.4.0.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate libtinyxml2.4.dylib

libtinyxml2.dylib: libtinyxml2.4.0.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate libtinyxml2.dylib

# Rule to build all files generated by this target.
CMakeFiles/tinyxml2.dir/build: libtinyxml2.dylib

.PHONY : CMakeFiles/tinyxml2.dir/build

CMakeFiles/tinyxml2.dir/requires: CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o.requires

.PHONY : CMakeFiles/tinyxml2.dir/requires

CMakeFiles/tinyxml2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tinyxml2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tinyxml2.dir/clean

CMakeFiles/tinyxml2.dir/depend:
	cd /Users/admos/AlgorithmPractice/tinyxml2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/admos/AlgorithmPractice/tinyxml2 /Users/admos/AlgorithmPractice/tinyxml2 /Users/admos/AlgorithmPractice/tinyxml2 /Users/admos/AlgorithmPractice/tinyxml2 /Users/admos/AlgorithmPractice/tinyxml2/CMakeFiles/tinyxml2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tinyxml2.dir/depend

