# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/andrew/server/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/server/Client/build

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/main.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/server/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/main.cpp.o -c /home/andrew/server/Client/main.cpp

CMakeFiles/client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/server/Client/main.cpp > CMakeFiles/client.dir/main.cpp.i

CMakeFiles/client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/server/Client/main.cpp -o CMakeFiles/client.dir/main.cpp.s

CMakeFiles/client.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/main.cpp.o.requires

CMakeFiles/client.dir/main.cpp.o.provides: CMakeFiles/client.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/main.cpp.o.provides

CMakeFiles/client.dir/main.cpp.o.provides.build: CMakeFiles/client.dir/main.cpp.o


CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o: ../IConnection/Connection/Connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/server/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o -c /home/andrew/server/Client/IConnection/Connection/Connection.cpp

CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/server/Client/IConnection/Connection/Connection.cpp > CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.i

CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/server/Client/IConnection/Connection/Connection.cpp -o CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.s

CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o.requires

CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o.provides: CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o.provides

CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o.provides.build: CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o


CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o: ../InitialConditions/JSONSerialize/JsonInitialConditions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/server/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o -c /home/andrew/server/Client/InitialConditions/JSONSerialize/JsonInitialConditions.cpp

CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/server/Client/InitialConditions/JSONSerialize/JsonInitialConditions.cpp > CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.i

CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/server/Client/InitialConditions/JSONSerialize/JsonInitialConditions.cpp -o CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.s

CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o.requires

CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o.provides: CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o.provides

CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o.provides.build: CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o


# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/main.cpp.o" \
"CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o" \
"CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/main.cpp.o
client: CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o
client: CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o
client: CMakeFiles/client.dir/build.make
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrew/server/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/requires: CMakeFiles/client.dir/main.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/IConnection/Connection/Connection.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/InitialConditions/JSONSerialize/JsonInitialConditions.cpp.o.requires

.PHONY : CMakeFiles/client.dir/requires

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/andrew/server/Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/server/Client /home/andrew/server/Client /home/andrew/server/Client/build /home/andrew/server/Client/build /home/andrew/server/Client/build/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend

