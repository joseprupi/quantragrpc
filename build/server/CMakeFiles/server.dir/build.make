# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /root/quantra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/quantra/build

# Include any dependencies generated for this target.
include server/CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include server/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include server/CMakeFiles/server.dir/flags.make

server/CMakeFiles/server.dir/__/common/common.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/__/common/common.o: ../common/common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/quantra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object server/CMakeFiles/server.dir/__/common/common.o"
	cd /root/quantra/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/__/common/common.o -c /root/quantra/common/common.cpp

server/CMakeFiles/server.dir/__/common/common.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/__/common/common.i"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/quantra/common/common.cpp > CMakeFiles/server.dir/__/common/common.i

server/CMakeFiles/server.dir/__/common/common.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/__/common/common.s"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/quantra/common/common.cpp -o CMakeFiles/server.dir/__/common/common.s

server/CMakeFiles/server.dir/__/common/enums.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/__/common/enums.o: ../common/enums.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/quantra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object server/CMakeFiles/server.dir/__/common/enums.o"
	cd /root/quantra/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/__/common/enums.o -c /root/quantra/common/enums.cpp

server/CMakeFiles/server.dir/__/common/enums.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/__/common/enums.i"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/quantra/common/enums.cpp > CMakeFiles/server.dir/__/common/enums.i

server/CMakeFiles/server.dir/__/common/enums.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/__/common/enums.s"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/quantra/common/enums.cpp -o CMakeFiles/server.dir/__/common/enums.s

server/CMakeFiles/server.dir/__/parser/common_parser.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/__/parser/common_parser.o: ../parser/common_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/quantra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object server/CMakeFiles/server.dir/__/parser/common_parser.o"
	cd /root/quantra/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/__/parser/common_parser.o -c /root/quantra/parser/common_parser.cpp

server/CMakeFiles/server.dir/__/parser/common_parser.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/__/parser/common_parser.i"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/quantra/parser/common_parser.cpp > CMakeFiles/server.dir/__/parser/common_parser.i

server/CMakeFiles/server.dir/__/parser/common_parser.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/__/parser/common_parser.s"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/quantra/parser/common_parser.cpp -o CMakeFiles/server.dir/__/parser/common_parser.s

server/CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.o: ../parser/fixed_rate_bond_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/quantra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object server/CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.o"
	cd /root/quantra/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.o -c /root/quantra/parser/fixed_rate_bond_parser.cpp

server/CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.i"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/quantra/parser/fixed_rate_bond_parser.cpp > CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.i

server/CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.s"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/quantra/parser/fixed_rate_bond_parser.cpp -o CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.s

server/CMakeFiles/server.dir/__/parser/term_structure_parser.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/__/parser/term_structure_parser.o: ../parser/term_structure_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/quantra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object server/CMakeFiles/server.dir/__/parser/term_structure_parser.o"
	cd /root/quantra/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/__/parser/term_structure_parser.o -c /root/quantra/parser/term_structure_parser.cpp

server/CMakeFiles/server.dir/__/parser/term_structure_parser.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/__/parser/term_structure_parser.i"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/quantra/parser/term_structure_parser.cpp > CMakeFiles/server.dir/__/parser/term_structure_parser.i

server/CMakeFiles/server.dir/__/parser/term_structure_parser.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/__/parser/term_structure_parser.s"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/quantra/parser/term_structure_parser.cpp -o CMakeFiles/server.dir/__/parser/term_structure_parser.s

server/CMakeFiles/server.dir/__/parser/term_structure_point_parser.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/__/parser/term_structure_point_parser.o: ../parser/term_structure_point_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/quantra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object server/CMakeFiles/server.dir/__/parser/term_structure_point_parser.o"
	cd /root/quantra/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/__/parser/term_structure_point_parser.o -c /root/quantra/parser/term_structure_point_parser.cpp

server/CMakeFiles/server.dir/__/parser/term_structure_point_parser.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/__/parser/term_structure_point_parser.i"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/quantra/parser/term_structure_point_parser.cpp > CMakeFiles/server.dir/__/parser/term_structure_point_parser.i

server/CMakeFiles/server.dir/__/parser/term_structure_point_parser.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/__/parser/term_structure_point_parser.s"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/quantra/parser/term_structure_point_parser.cpp -o CMakeFiles/server.dir/__/parser/term_structure_point_parser.s

server/CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.o: ../request/fixed_rate_bond_pricing_request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/quantra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object server/CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.o"
	cd /root/quantra/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.o -c /root/quantra/request/fixed_rate_bond_pricing_request.cpp

server/CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.i"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/quantra/request/fixed_rate_bond_pricing_request.cpp > CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.i

server/CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.s"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/quantra/request/fixed_rate_bond_pricing_request.cpp -o CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.s

server/CMakeFiles/server.dir/sync_server.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/sync_server.o: ../server/sync_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/quantra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object server/CMakeFiles/server.dir/sync_server.o"
	cd /root/quantra/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/sync_server.o -c /root/quantra/server/sync_server.cpp

server/CMakeFiles/server.dir/sync_server.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/sync_server.i"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/quantra/server/sync_server.cpp > CMakeFiles/server.dir/sync_server.i

server/CMakeFiles/server.dir/sync_server.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/sync_server.s"
	cd /root/quantra/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/quantra/server/sync_server.cpp -o CMakeFiles/server.dir/sync_server.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/__/common/common.o" \
"CMakeFiles/server.dir/__/common/enums.o" \
"CMakeFiles/server.dir/__/parser/common_parser.o" \
"CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.o" \
"CMakeFiles/server.dir/__/parser/term_structure_parser.o" \
"CMakeFiles/server.dir/__/parser/term_structure_point_parser.o" \
"CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.o" \
"CMakeFiles/server.dir/sync_server.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server/server: server/CMakeFiles/server.dir/__/common/common.o
server/server: server/CMakeFiles/server.dir/__/common/enums.o
server/server: server/CMakeFiles/server.dir/__/parser/common_parser.o
server/server: server/CMakeFiles/server.dir/__/parser/fixed_rate_bond_parser.o
server/server: server/CMakeFiles/server.dir/__/parser/term_structure_parser.o
server/server: server/CMakeFiles/server.dir/__/parser/term_structure_point_parser.o
server/server: server/CMakeFiles/server.dir/__/request/fixed_rate_bond_pricing_request.o
server/server: server/CMakeFiles/server.dir/sync_server.o
server/server: server/CMakeFiles/server.dir/build.make
server/server: grpc/libquantra_grpc.a
server/server: server/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/quantra/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable server"
	cd /root/quantra/build/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server/CMakeFiles/server.dir/build: server/server

.PHONY : server/CMakeFiles/server.dir/build

server/CMakeFiles/server.dir/clean:
	cd /root/quantra/build/server && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : server/CMakeFiles/server.dir/clean

server/CMakeFiles/server.dir/depend:
	cd /root/quantra/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/quantra /root/quantra/server /root/quantra/build /root/quantra/build/server /root/quantra/build/server/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server/CMakeFiles/server.dir/depend

