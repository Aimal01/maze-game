# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/aimal/Downloads/maze_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aimal/Downloads/maze_game/build

# Include any dependencies generated for this target.
include CMakeFiles/maze_game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/maze_game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/maze_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/maze_game.dir/flags.make

CMakeFiles/maze_game.dir/src/Button.cpp.o: CMakeFiles/maze_game.dir/flags.make
CMakeFiles/maze_game.dir/src/Button.cpp.o: /home/aimal/Downloads/maze_game/src/Button.cpp
CMakeFiles/maze_game.dir/src/Button.cpp.o: CMakeFiles/maze_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aimal/Downloads/maze_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/maze_game.dir/src/Button.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/maze_game.dir/src/Button.cpp.o -MF CMakeFiles/maze_game.dir/src/Button.cpp.o.d -o CMakeFiles/maze_game.dir/src/Button.cpp.o -c /home/aimal/Downloads/maze_game/src/Button.cpp

CMakeFiles/maze_game.dir/src/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/maze_game.dir/src/Button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aimal/Downloads/maze_game/src/Button.cpp > CMakeFiles/maze_game.dir/src/Button.cpp.i

CMakeFiles/maze_game.dir/src/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/maze_game.dir/src/Button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aimal/Downloads/maze_game/src/Button.cpp -o CMakeFiles/maze_game.dir/src/Button.cpp.s

CMakeFiles/maze_game.dir/src/Enemy.cpp.o: CMakeFiles/maze_game.dir/flags.make
CMakeFiles/maze_game.dir/src/Enemy.cpp.o: /home/aimal/Downloads/maze_game/src/Enemy.cpp
CMakeFiles/maze_game.dir/src/Enemy.cpp.o: CMakeFiles/maze_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aimal/Downloads/maze_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/maze_game.dir/src/Enemy.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/maze_game.dir/src/Enemy.cpp.o -MF CMakeFiles/maze_game.dir/src/Enemy.cpp.o.d -o CMakeFiles/maze_game.dir/src/Enemy.cpp.o -c /home/aimal/Downloads/maze_game/src/Enemy.cpp

CMakeFiles/maze_game.dir/src/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/maze_game.dir/src/Enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aimal/Downloads/maze_game/src/Enemy.cpp > CMakeFiles/maze_game.dir/src/Enemy.cpp.i

CMakeFiles/maze_game.dir/src/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/maze_game.dir/src/Enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aimal/Downloads/maze_game/src/Enemy.cpp -o CMakeFiles/maze_game.dir/src/Enemy.cpp.s

CMakeFiles/maze_game.dir/src/MazeGame.cpp.o: CMakeFiles/maze_game.dir/flags.make
CMakeFiles/maze_game.dir/src/MazeGame.cpp.o: /home/aimal/Downloads/maze_game/src/MazeGame.cpp
CMakeFiles/maze_game.dir/src/MazeGame.cpp.o: CMakeFiles/maze_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aimal/Downloads/maze_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/maze_game.dir/src/MazeGame.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/maze_game.dir/src/MazeGame.cpp.o -MF CMakeFiles/maze_game.dir/src/MazeGame.cpp.o.d -o CMakeFiles/maze_game.dir/src/MazeGame.cpp.o -c /home/aimal/Downloads/maze_game/src/MazeGame.cpp

CMakeFiles/maze_game.dir/src/MazeGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/maze_game.dir/src/MazeGame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aimal/Downloads/maze_game/src/MazeGame.cpp > CMakeFiles/maze_game.dir/src/MazeGame.cpp.i

CMakeFiles/maze_game.dir/src/MazeGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/maze_game.dir/src/MazeGame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aimal/Downloads/maze_game/src/MazeGame.cpp -o CMakeFiles/maze_game.dir/src/MazeGame.cpp.s

CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.o: CMakeFiles/maze_game.dir/flags.make
CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.o: /home/aimal/Downloads/maze_game/src/ParticleSystem.cpp
CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.o: CMakeFiles/maze_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aimal/Downloads/maze_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.o -MF CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.o.d -o CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.o -c /home/aimal/Downloads/maze_game/src/ParticleSystem.cpp

CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aimal/Downloads/maze_game/src/ParticleSystem.cpp > CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.i

CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aimal/Downloads/maze_game/src/ParticleSystem.cpp -o CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.s

CMakeFiles/maze_game.dir/src/PowerUp.cpp.o: CMakeFiles/maze_game.dir/flags.make
CMakeFiles/maze_game.dir/src/PowerUp.cpp.o: /home/aimal/Downloads/maze_game/src/PowerUp.cpp
CMakeFiles/maze_game.dir/src/PowerUp.cpp.o: CMakeFiles/maze_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aimal/Downloads/maze_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/maze_game.dir/src/PowerUp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/maze_game.dir/src/PowerUp.cpp.o -MF CMakeFiles/maze_game.dir/src/PowerUp.cpp.o.d -o CMakeFiles/maze_game.dir/src/PowerUp.cpp.o -c /home/aimal/Downloads/maze_game/src/PowerUp.cpp

CMakeFiles/maze_game.dir/src/PowerUp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/maze_game.dir/src/PowerUp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aimal/Downloads/maze_game/src/PowerUp.cpp > CMakeFiles/maze_game.dir/src/PowerUp.cpp.i

CMakeFiles/maze_game.dir/src/PowerUp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/maze_game.dir/src/PowerUp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aimal/Downloads/maze_game/src/PowerUp.cpp -o CMakeFiles/maze_game.dir/src/PowerUp.cpp.s

CMakeFiles/maze_game.dir/src/main.cpp.o: CMakeFiles/maze_game.dir/flags.make
CMakeFiles/maze_game.dir/src/main.cpp.o: /home/aimal/Downloads/maze_game/src/main.cpp
CMakeFiles/maze_game.dir/src/main.cpp.o: CMakeFiles/maze_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/aimal/Downloads/maze_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/maze_game.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/maze_game.dir/src/main.cpp.o -MF CMakeFiles/maze_game.dir/src/main.cpp.o.d -o CMakeFiles/maze_game.dir/src/main.cpp.o -c /home/aimal/Downloads/maze_game/src/main.cpp

CMakeFiles/maze_game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/maze_game.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aimal/Downloads/maze_game/src/main.cpp > CMakeFiles/maze_game.dir/src/main.cpp.i

CMakeFiles/maze_game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/maze_game.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aimal/Downloads/maze_game/src/main.cpp -o CMakeFiles/maze_game.dir/src/main.cpp.s

# Object files for target maze_game
maze_game_OBJECTS = \
"CMakeFiles/maze_game.dir/src/Button.cpp.o" \
"CMakeFiles/maze_game.dir/src/Enemy.cpp.o" \
"CMakeFiles/maze_game.dir/src/MazeGame.cpp.o" \
"CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.o" \
"CMakeFiles/maze_game.dir/src/PowerUp.cpp.o" \
"CMakeFiles/maze_game.dir/src/main.cpp.o"

# External object files for target maze_game
maze_game_EXTERNAL_OBJECTS =

maze_game: CMakeFiles/maze_game.dir/src/Button.cpp.o
maze_game: CMakeFiles/maze_game.dir/src/Enemy.cpp.o
maze_game: CMakeFiles/maze_game.dir/src/MazeGame.cpp.o
maze_game: CMakeFiles/maze_game.dir/src/ParticleSystem.cpp.o
maze_game: CMakeFiles/maze_game.dir/src/PowerUp.cpp.o
maze_game: CMakeFiles/maze_game.dir/src/main.cpp.o
maze_game: CMakeFiles/maze_game.dir/build.make
maze_game: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.6.1
maze_game: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.6.1
maze_game: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.6.1
maze_game: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.6.1
maze_game: CMakeFiles/maze_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/aimal/Downloads/maze_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable maze_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/maze_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/maze_game.dir/build: maze_game
.PHONY : CMakeFiles/maze_game.dir/build

CMakeFiles/maze_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/maze_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/maze_game.dir/clean

CMakeFiles/maze_game.dir/depend:
	cd /home/aimal/Downloads/maze_game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aimal/Downloads/maze_game /home/aimal/Downloads/maze_game /home/aimal/Downloads/maze_game/build /home/aimal/Downloads/maze_game/build /home/aimal/Downloads/maze_game/build/CMakeFiles/maze_game.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/maze_game.dir/depend

