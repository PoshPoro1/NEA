# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_SOURCE_DIR = /home/ryom/Documents/Programming/CPPPrograms/NEA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ryom/Documents/Programming/CPPPrograms/NEA

# Include any dependencies generated for this target.
include CMakeFiles/Suspect.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Suspect.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Suspect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Suspect.dir/flags.make

CMakeFiles/Suspect.dir/src/main.cpp.o: CMakeFiles/Suspect.dir/flags.make
CMakeFiles/Suspect.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/Suspect.dir/src/main.cpp.o: CMakeFiles/Suspect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ryom/Documents/Programming/CPPPrograms/NEA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Suspect.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Suspect.dir/src/main.cpp.o -MF CMakeFiles/Suspect.dir/src/main.cpp.o.d -o CMakeFiles/Suspect.dir/src/main.cpp.o -c /home/ryom/Documents/Programming/CPPPrograms/NEA/src/main.cpp

CMakeFiles/Suspect.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Suspect.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ryom/Documents/Programming/CPPPrograms/NEA/src/main.cpp > CMakeFiles/Suspect.dir/src/main.cpp.i

CMakeFiles/Suspect.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Suspect.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ryom/Documents/Programming/CPPPrograms/NEA/src/main.cpp -o CMakeFiles/Suspect.dir/src/main.cpp.s

CMakeFiles/Suspect.dir/src/glad.c.o: CMakeFiles/Suspect.dir/flags.make
CMakeFiles/Suspect.dir/src/glad.c.o: src/glad.c
CMakeFiles/Suspect.dir/src/glad.c.o: CMakeFiles/Suspect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ryom/Documents/Programming/CPPPrograms/NEA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Suspect.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Suspect.dir/src/glad.c.o -MF CMakeFiles/Suspect.dir/src/glad.c.o.d -o CMakeFiles/Suspect.dir/src/glad.c.o -c /home/ryom/Documents/Programming/CPPPrograms/NEA/src/glad.c

CMakeFiles/Suspect.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Suspect.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ryom/Documents/Programming/CPPPrograms/NEA/src/glad.c > CMakeFiles/Suspect.dir/src/glad.c.i

CMakeFiles/Suspect.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Suspect.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ryom/Documents/Programming/CPPPrograms/NEA/src/glad.c -o CMakeFiles/Suspect.dir/src/glad.c.s

CMakeFiles/Suspect.dir/src/shader.cpp.o: CMakeFiles/Suspect.dir/flags.make
CMakeFiles/Suspect.dir/src/shader.cpp.o: src/shader.cpp
CMakeFiles/Suspect.dir/src/shader.cpp.o: CMakeFiles/Suspect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ryom/Documents/Programming/CPPPrograms/NEA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Suspect.dir/src/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Suspect.dir/src/shader.cpp.o -MF CMakeFiles/Suspect.dir/src/shader.cpp.o.d -o CMakeFiles/Suspect.dir/src/shader.cpp.o -c /home/ryom/Documents/Programming/CPPPrograms/NEA/src/shader.cpp

CMakeFiles/Suspect.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Suspect.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ryom/Documents/Programming/CPPPrograms/NEA/src/shader.cpp > CMakeFiles/Suspect.dir/src/shader.cpp.i

CMakeFiles/Suspect.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Suspect.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ryom/Documents/Programming/CPPPrograms/NEA/src/shader.cpp -o CMakeFiles/Suspect.dir/src/shader.cpp.s

# Object files for target Suspect
Suspect_OBJECTS = \
"CMakeFiles/Suspect.dir/src/main.cpp.o" \
"CMakeFiles/Suspect.dir/src/glad.c.o" \
"CMakeFiles/Suspect.dir/src/shader.cpp.o"

# External object files for target Suspect
Suspect_EXTERNAL_OBJECTS =

Suspect: CMakeFiles/Suspect.dir/src/main.cpp.o
Suspect: CMakeFiles/Suspect.dir/src/glad.c.o
Suspect: CMakeFiles/Suspect.dir/src/shader.cpp.o
Suspect: CMakeFiles/Suspect.dir/build.make
Suspect: /usr/local/lib/libglfw3.a
Suspect: /usr/lib/librt.a
Suspect: /usr/lib/libm.so
Suspect: /usr/lib/libX11.so
Suspect: CMakeFiles/Suspect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ryom/Documents/Programming/CPPPrograms/NEA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Suspect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Suspect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Suspect.dir/build: Suspect
.PHONY : CMakeFiles/Suspect.dir/build

CMakeFiles/Suspect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Suspect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Suspect.dir/clean

CMakeFiles/Suspect.dir/depend:
	cd /home/ryom/Documents/Programming/CPPPrograms/NEA && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ryom/Documents/Programming/CPPPrograms/NEA /home/ryom/Documents/Programming/CPPPrograms/NEA /home/ryom/Documents/Programming/CPPPrograms/NEA /home/ryom/Documents/Programming/CPPPrograms/NEA /home/ryom/Documents/Programming/CPPPrograms/NEA/CMakeFiles/Suspect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Suspect.dir/depend
