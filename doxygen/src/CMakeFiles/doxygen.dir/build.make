# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.3_1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen

# Include any dependencies generated for this target.
include src/CMakeFiles/doxygen.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/doxygen.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/doxygen.dir/flags.make

src/CMakeFiles/doxygen.dir/main.cpp.o: src/CMakeFiles/doxygen.dir/flags.make
src/CMakeFiles/doxygen.dir/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/doxygen.dir/main.cpp.o"
	cd /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doxygen.dir/main.cpp.o -c /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src/main.cpp

src/CMakeFiles/doxygen.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doxygen.dir/main.cpp.i"
	cd /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src/main.cpp > CMakeFiles/doxygen.dir/main.cpp.i

src/CMakeFiles/doxygen.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doxygen.dir/main.cpp.s"
	cd /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src/main.cpp -o CMakeFiles/doxygen.dir/main.cpp.s

src/CMakeFiles/doxygen.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/doxygen.dir/main.cpp.o.requires

src/CMakeFiles/doxygen.dir/main.cpp.o.provides: src/CMakeFiles/doxygen.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/doxygen.dir/build.make src/CMakeFiles/doxygen.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/doxygen.dir/main.cpp.o.provides

src/CMakeFiles/doxygen.dir/main.cpp.o.provides.build: src/CMakeFiles/doxygen.dir/main.cpp.o


# Object files for target doxygen
doxygen_OBJECTS = \
"CMakeFiles/doxygen.dir/main.cpp.o"

# External object files for target doxygen
doxygen_EXTERNAL_OBJECTS =

bin/doxygen: src/CMakeFiles/doxygen.dir/main.cpp.o
bin/doxygen: src/CMakeFiles/doxygen.dir/build.make
bin/doxygen: lib/lib_doxygen.a
bin/doxygen: lib/libdoxycfg.a
bin/doxygen: lib/libqtools.a
bin/doxygen: lib/libmd5.a
bin/doxygen: lib/libvhdlparser.a
bin/doxygen: /usr/lib/libiconv.dylib
bin/doxygen: src/CMakeFiles/doxygen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/doxygen"
	cd /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/doxygen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/doxygen.dir/build: bin/doxygen

.PHONY : src/CMakeFiles/doxygen.dir/build

src/CMakeFiles/doxygen.dir/requires: src/CMakeFiles/doxygen.dir/main.cpp.o.requires

.PHONY : src/CMakeFiles/doxygen.dir/requires

src/CMakeFiles/doxygen.dir/clean:
	cd /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src && $(CMAKE_COMMAND) -P CMakeFiles/doxygen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/doxygen.dir/clean

src/CMakeFiles/doxygen.dir/depend:
	cd /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src /Users/anoukrossier/Documents/EPFL/BA3/Prog/Neuronint/doxygen/src/CMakeFiles/doxygen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/doxygen.dir/depend
