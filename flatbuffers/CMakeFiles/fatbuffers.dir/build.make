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
CMAKE_SOURCE_DIR = /root/quantragrpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/quantragrpc

# Utility rule file for fatbuffers.

# Include the progress variables for this target.
include flatbuffers/CMakeFiles/fatbuffers.dir/progress.make

flatbuffers/CMakeFiles/fatbuffers: flatbuffers/fbs/fbs.stamp


flatbuffers/fbs/fbs.stamp: flatbuffers/fbs/*.fbs
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/quantragrpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating fbs/fbs.stamp"
	cd /root/quantragrpc/flatbuffers && flatc --cpp --gen-object-api -o /root/quantragrpc/flatbuffers/cpp /root/quantragrpc/flatbuffers/fbs/*.fbs
	cd /root/quantragrpc/flatbuffers && flatc --python -o /root/quantragrpc/flatbuffers/python /root/quantragrpc/flatbuffers/fbs/*.fbs

fatbuffers: flatbuffers/CMakeFiles/fatbuffers
fatbuffers: flatbuffers/fbs/fbs.stamp
fatbuffers: flatbuffers/CMakeFiles/fatbuffers.dir/build.make

.PHONY : fatbuffers

# Rule to build all files generated by this target.
flatbuffers/CMakeFiles/fatbuffers.dir/build: fatbuffers

.PHONY : flatbuffers/CMakeFiles/fatbuffers.dir/build

flatbuffers/CMakeFiles/fatbuffers.dir/clean:
	cd /root/quantragrpc/flatbuffers && $(CMAKE_COMMAND) -P CMakeFiles/fatbuffers.dir/cmake_clean.cmake
.PHONY : flatbuffers/CMakeFiles/fatbuffers.dir/clean

flatbuffers/CMakeFiles/fatbuffers.dir/depend:
	cd /root/quantragrpc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/quantragrpc /root/quantragrpc/flatbuffers /root/quantragrpc /root/quantragrpc/flatbuffers /root/quantragrpc/flatbuffers/CMakeFiles/fatbuffers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : flatbuffers/CMakeFiles/fatbuffers.dir/depend
