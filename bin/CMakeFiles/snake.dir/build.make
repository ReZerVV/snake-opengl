# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cyril/Programming/snake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cyril/Programming/snake/bin

# Include any dependencies generated for this target.
include CMakeFiles/snake.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/snake.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/snake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snake.dir/flags.make

CMakeFiles/snake.dir/source/main.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/source/main.cpp.o: /home/cyril/Programming/snake/source/main.cpp
CMakeFiles/snake.dir/source/main.cpp.o: CMakeFiles/snake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyril/Programming/snake/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/snake.dir/source/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake.dir/source/main.cpp.o -MF CMakeFiles/snake.dir/source/main.cpp.o.d -o CMakeFiles/snake.dir/source/main.cpp.o -c /home/cyril/Programming/snake/source/main.cpp

CMakeFiles/snake.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyril/Programming/snake/source/main.cpp > CMakeFiles/snake.dir/source/main.cpp.i

CMakeFiles/snake.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyril/Programming/snake/source/main.cpp -o CMakeFiles/snake.dir/source/main.cpp.s

CMakeFiles/snake.dir/source/snake.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/source/snake.cpp.o: /home/cyril/Programming/snake/source/snake.cpp
CMakeFiles/snake.dir/source/snake.cpp.o: CMakeFiles/snake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyril/Programming/snake/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/snake.dir/source/snake.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake.dir/source/snake.cpp.o -MF CMakeFiles/snake.dir/source/snake.cpp.o.d -o CMakeFiles/snake.dir/source/snake.cpp.o -c /home/cyril/Programming/snake/source/snake.cpp

CMakeFiles/snake.dir/source/snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/source/snake.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyril/Programming/snake/source/snake.cpp > CMakeFiles/snake.dir/source/snake.cpp.i

CMakeFiles/snake.dir/source/snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/source/snake.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyril/Programming/snake/source/snake.cpp -o CMakeFiles/snake.dir/source/snake.cpp.s

CMakeFiles/snake.dir/source/food.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/source/food.cpp.o: /home/cyril/Programming/snake/source/food.cpp
CMakeFiles/snake.dir/source/food.cpp.o: CMakeFiles/snake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyril/Programming/snake/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/snake.dir/source/food.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake.dir/source/food.cpp.o -MF CMakeFiles/snake.dir/source/food.cpp.o.d -o CMakeFiles/snake.dir/source/food.cpp.o -c /home/cyril/Programming/snake/source/food.cpp

CMakeFiles/snake.dir/source/food.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/source/food.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyril/Programming/snake/source/food.cpp > CMakeFiles/snake.dir/source/food.cpp.i

CMakeFiles/snake.dir/source/food.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/source/food.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyril/Programming/snake/source/food.cpp -o CMakeFiles/snake.dir/source/food.cpp.s

CMakeFiles/snake.dir/source/map.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/source/map.cpp.o: /home/cyril/Programming/snake/source/map.cpp
CMakeFiles/snake.dir/source/map.cpp.o: CMakeFiles/snake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyril/Programming/snake/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/snake.dir/source/map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake.dir/source/map.cpp.o -MF CMakeFiles/snake.dir/source/map.cpp.o.d -o CMakeFiles/snake.dir/source/map.cpp.o -c /home/cyril/Programming/snake/source/map.cpp

CMakeFiles/snake.dir/source/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/source/map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyril/Programming/snake/source/map.cpp > CMakeFiles/snake.dir/source/map.cpp.i

CMakeFiles/snake.dir/source/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/source/map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyril/Programming/snake/source/map.cpp -o CMakeFiles/snake.dir/source/map.cpp.s

CMakeFiles/snake.dir/source/controller.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/source/controller.cpp.o: /home/cyril/Programming/snake/source/controller.cpp
CMakeFiles/snake.dir/source/controller.cpp.o: CMakeFiles/snake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyril/Programming/snake/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/snake.dir/source/controller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake.dir/source/controller.cpp.o -MF CMakeFiles/snake.dir/source/controller.cpp.o.d -o CMakeFiles/snake.dir/source/controller.cpp.o -c /home/cyril/Programming/snake/source/controller.cpp

CMakeFiles/snake.dir/source/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/source/controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyril/Programming/snake/source/controller.cpp > CMakeFiles/snake.dir/source/controller.cpp.i

CMakeFiles/snake.dir/source/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/source/controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyril/Programming/snake/source/controller.cpp -o CMakeFiles/snake.dir/source/controller.cpp.s

CMakeFiles/snake.dir/source/shader.cpp.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/source/shader.cpp.o: /home/cyril/Programming/snake/source/shader.cpp
CMakeFiles/snake.dir/source/shader.cpp.o: CMakeFiles/snake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyril/Programming/snake/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/snake.dir/source/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/snake.dir/source/shader.cpp.o -MF CMakeFiles/snake.dir/source/shader.cpp.o.d -o CMakeFiles/snake.dir/source/shader.cpp.o -c /home/cyril/Programming/snake/source/shader.cpp

CMakeFiles/snake.dir/source/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snake.dir/source/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyril/Programming/snake/source/shader.cpp > CMakeFiles/snake.dir/source/shader.cpp.i

CMakeFiles/snake.dir/source/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snake.dir/source/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyril/Programming/snake/source/shader.cpp -o CMakeFiles/snake.dir/source/shader.cpp.s

# Object files for target snake
snake_OBJECTS = \
"CMakeFiles/snake.dir/source/main.cpp.o" \
"CMakeFiles/snake.dir/source/snake.cpp.o" \
"CMakeFiles/snake.dir/source/food.cpp.o" \
"CMakeFiles/snake.dir/source/map.cpp.o" \
"CMakeFiles/snake.dir/source/controller.cpp.o" \
"CMakeFiles/snake.dir/source/shader.cpp.o"

# External object files for target snake
snake_EXTERNAL_OBJECTS =

snake: CMakeFiles/snake.dir/source/main.cpp.o
snake: CMakeFiles/snake.dir/source/snake.cpp.o
snake: CMakeFiles/snake.dir/source/food.cpp.o
snake: CMakeFiles/snake.dir/source/map.cpp.o
snake: CMakeFiles/snake.dir/source/controller.cpp.o
snake: CMakeFiles/snake.dir/source/shader.cpp.o
snake: CMakeFiles/snake.dir/build.make
snake: /usr/lib/libGL.so
snake: /usr/lib/libGLEW.so
snake: CMakeFiles/snake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cyril/Programming/snake/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable snake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snake.dir/build: snake
.PHONY : CMakeFiles/snake.dir/build

CMakeFiles/snake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/snake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/snake.dir/clean

CMakeFiles/snake.dir/depend:
	cd /home/cyril/Programming/snake/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cyril/Programming/snake /home/cyril/Programming/snake /home/cyril/Programming/snake/bin /home/cyril/Programming/snake/bin /home/cyril/Programming/snake/bin/CMakeFiles/snake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snake.dir/depend

