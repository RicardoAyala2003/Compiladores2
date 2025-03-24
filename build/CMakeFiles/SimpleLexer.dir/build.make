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
CMAKE_SOURCE_DIR = /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build

# Include any dependencies generated for this target.
include CMakeFiles/SimpleLexer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SimpleLexer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleLexer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleLexer.dir/flags.make

tokens.hpp: /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/SimpleLexer.l
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating lexer source file with Reflex"
	/usr/local/bin/reflex -o SimpleLexer.cpp --header-file=SimpleLexer.hpp /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/SimpleLexer.l

SimpleLexer.cpp: tokens.hpp
	@$(CMAKE_COMMAND) -E touch_nocreate SimpleLexer.cpp

SimpleLexer.hpp: tokens.hpp
	@$(CMAKE_COMMAND) -E touch_nocreate SimpleLexer.hpp

SimpleParser.cpp: /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/SimpleParser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[BISON][SimpleParser] Building parser with bison 3.8.2"
	cd /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer && /usr/bin/bison --defines=/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/SimpleParser.hpp -o /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/SimpleParser.cpp SimpleParser.y

SimpleParser.hpp: SimpleParser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate SimpleParser.hpp

ExprAst.cpp: /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating AST source file with TreeCC"
	/usr/local/bin/treecc -o ExprAst.cpp -h ExprAst.hpp /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc

ExprAst.hpp: ExprAst.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ExprAst.hpp

CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.o: CMakeFiles/SimpleLexer.dir/flags.make
CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.o: SimpleLexer.cpp
CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.o: CMakeFiles/SimpleLexer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.o -MF CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.o.d -o CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.o -c /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/SimpleLexer.cpp

CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/SimpleLexer.cpp > CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.i

CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/SimpleLexer.cpp -o CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.s

CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.o: CMakeFiles/SimpleLexer.dir/flags.make
CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.o: SimpleParser.cpp
CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.o: CMakeFiles/SimpleLexer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.o -MF CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.o.d -o CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.o -c /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/SimpleParser.cpp

CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/SimpleParser.cpp > CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.i

CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/SimpleParser.cpp -o CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.s

CMakeFiles/SimpleLexer.dir/ExprAst.cpp.o: CMakeFiles/SimpleLexer.dir/flags.make
CMakeFiles/SimpleLexer.dir/ExprAst.cpp.o: ExprAst.cpp
CMakeFiles/SimpleLexer.dir/ExprAst.cpp.o: CMakeFiles/SimpleLexer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SimpleLexer.dir/ExprAst.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimpleLexer.dir/ExprAst.cpp.o -MF CMakeFiles/SimpleLexer.dir/ExprAst.cpp.o.d -o CMakeFiles/SimpleLexer.dir/ExprAst.cpp.o -c /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/ExprAst.cpp

CMakeFiles/SimpleLexer.dir/ExprAst.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimpleLexer.dir/ExprAst.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/ExprAst.cpp > CMakeFiles/SimpleLexer.dir/ExprAst.cpp.i

CMakeFiles/SimpleLexer.dir/ExprAst.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimpleLexer.dir/ExprAst.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/ExprAst.cpp -o CMakeFiles/SimpleLexer.dir/ExprAst.cpp.s

CMakeFiles/SimpleLexer.dir/main.cpp.o: CMakeFiles/SimpleLexer.dir/flags.make
CMakeFiles/SimpleLexer.dir/main.cpp.o: /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/main.cpp
CMakeFiles/SimpleLexer.dir/main.cpp.o: CMakeFiles/SimpleLexer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SimpleLexer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimpleLexer.dir/main.cpp.o -MF CMakeFiles/SimpleLexer.dir/main.cpp.o.d -o CMakeFiles/SimpleLexer.dir/main.cpp.o -c /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/main.cpp

CMakeFiles/SimpleLexer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimpleLexer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/main.cpp > CMakeFiles/SimpleLexer.dir/main.cpp.i

CMakeFiles/SimpleLexer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimpleLexer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/main.cpp -o CMakeFiles/SimpleLexer.dir/main.cpp.s

# Object files for target SimpleLexer
SimpleLexer_OBJECTS = \
"CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.o" \
"CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.o" \
"CMakeFiles/SimpleLexer.dir/ExprAst.cpp.o" \
"CMakeFiles/SimpleLexer.dir/main.cpp.o"

# External object files for target SimpleLexer
SimpleLexer_EXTERNAL_OBJECTS =

SimpleLexer: CMakeFiles/SimpleLexer.dir/SimpleLexer.cpp.o
SimpleLexer: CMakeFiles/SimpleLexer.dir/SimpleParser.cpp.o
SimpleLexer: CMakeFiles/SimpleLexer.dir/ExprAst.cpp.o
SimpleLexer: CMakeFiles/SimpleLexer.dir/main.cpp.o
SimpleLexer: CMakeFiles/SimpleLexer.dir/build.make
SimpleLexer: /usr/local/lib/libreflex_static_lib.a
SimpleLexer: CMakeFiles/SimpleLexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable SimpleLexer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleLexer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleLexer.dir/build: SimpleLexer
.PHONY : CMakeFiles/SimpleLexer.dir/build

CMakeFiles/SimpleLexer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleLexer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleLexer.dir/clean

CMakeFiles/SimpleLexer.dir/depend: ExprAst.cpp
CMakeFiles/SimpleLexer.dir/depend: ExprAst.hpp
CMakeFiles/SimpleLexer.dir/depend: SimpleLexer.cpp
CMakeFiles/SimpleLexer.dir/depend: SimpleLexer.hpp
CMakeFiles/SimpleLexer.dir/depend: SimpleParser.cpp
CMakeFiles/SimpleLexer.dir/depend: SimpleParser.hpp
CMakeFiles/SimpleLexer.dir/depend: tokens.hpp
	cd /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build /home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/build/CMakeFiles/SimpleLexer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SimpleLexer.dir/depend

