# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = C:\Users\Tony\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4127.32\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Tony\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4127.32\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj01.dir/flags.make

CMakeFiles/proj01.dir/main.cpp.obj: CMakeFiles/proj01.dir/flags.make
CMakeFiles/proj01.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj01.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\proj01.dir\main.cpp.obj -c C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01\main.cpp

CMakeFiles/proj01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj01.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01\main.cpp > CMakeFiles\proj01.dir\main.cpp.i

CMakeFiles/proj01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj01.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01\main.cpp -o CMakeFiles\proj01.dir\main.cpp.s

CMakeFiles/proj01.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/proj01.dir/main.cpp.obj.requires

CMakeFiles/proj01.dir/main.cpp.obj.provides: CMakeFiles/proj01.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\proj01.dir\build.make CMakeFiles/proj01.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/proj01.dir/main.cpp.obj.provides

CMakeFiles/proj01.dir/main.cpp.obj.provides.build: CMakeFiles/proj01.dir/main.cpp.obj


# Object files for target proj01
proj01_OBJECTS = \
"CMakeFiles/proj01.dir/main.cpp.obj"

# External object files for target proj01
proj01_EXTERNAL_OBJECTS =

proj01.exe: CMakeFiles/proj01.dir/main.cpp.obj
proj01.exe: CMakeFiles/proj01.dir/build.make
proj01.exe: CMakeFiles/proj01.dir/linklibs.rsp
proj01.exe: CMakeFiles/proj01.dir/objects1.rsp
proj01.exe: CMakeFiles/proj01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proj01.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proj01.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj01.dir/build: proj01.exe

.PHONY : CMakeFiles/proj01.dir/build

CMakeFiles/proj01.dir/requires: CMakeFiles/proj01.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/proj01.dir/requires

CMakeFiles/proj01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proj01.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proj01.dir/clean

CMakeFiles/proj01.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01 C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01 C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01\cmake-build-debug C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01\cmake-build-debug C:\Users\Tony\ClionProjects\CSE-232\Projects\proj01\cmake-build-debug\CMakeFiles\proj01.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj01.dir/depend

