# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\WISEM18\Semesterarbeit\Aufgabe3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\WISEM18\Semesterarbeit\Aufgabe3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Aufgabe3.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Aufgabe3.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Aufgabe3.dir\flags.make

CMakeFiles\Aufgabe3.dir\main.cpp.obj: CMakeFiles\Aufgabe3.dir\flags.make
CMakeFiles\Aufgabe3.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\WISEM18\Semesterarbeit\Aufgabe3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Aufgabe3.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Aufgabe3.dir\main.cpp.obj /FdCMakeFiles\Aufgabe3.dir\ /FS -c D:\WISEM18\Semesterarbeit\Aufgabe3\main.cpp
<<

CMakeFiles\Aufgabe3.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aufgabe3.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Aufgabe3.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\WISEM18\Semesterarbeit\Aufgabe3\main.cpp
<<

CMakeFiles\Aufgabe3.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aufgabe3.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Aufgabe3.dir\main.cpp.s /c D:\WISEM18\Semesterarbeit\Aufgabe3\main.cpp
<<

CMakeFiles\Aufgabe3.dir\lib\Denkmal.cpp.obj: CMakeFiles\Aufgabe3.dir\flags.make
CMakeFiles\Aufgabe3.dir\lib\Denkmal.cpp.obj: ..\lib\Denkmal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\WISEM18\Semesterarbeit\Aufgabe3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Aufgabe3.dir/lib/Denkmal.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Aufgabe3.dir\lib\Denkmal.cpp.obj /FdCMakeFiles\Aufgabe3.dir\ /FS -c D:\WISEM18\Semesterarbeit\Aufgabe3\lib\Denkmal.cpp
<<

CMakeFiles\Aufgabe3.dir\lib\Denkmal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aufgabe3.dir/lib/Denkmal.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\Aufgabe3.dir\lib\Denkmal.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\WISEM18\Semesterarbeit\Aufgabe3\lib\Denkmal.cpp
<<

CMakeFiles\Aufgabe3.dir\lib\Denkmal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aufgabe3.dir/lib/Denkmal.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Aufgabe3.dir\lib\Denkmal.cpp.s /c D:\WISEM18\Semesterarbeit\Aufgabe3\lib\Denkmal.cpp
<<

# Object files for target Aufgabe3
Aufgabe3_OBJECTS = \
"CMakeFiles\Aufgabe3.dir\main.cpp.obj" \
"CMakeFiles\Aufgabe3.dir\lib\Denkmal.cpp.obj"

# External object files for target Aufgabe3
Aufgabe3_EXTERNAL_OBJECTS =

Aufgabe3.exe: CMakeFiles\Aufgabe3.dir\main.cpp.obj
Aufgabe3.exe: CMakeFiles\Aufgabe3.dir\lib\Denkmal.cpp.obj
Aufgabe3.exe: CMakeFiles\Aufgabe3.dir\build.make
Aufgabe3.exe: CMakeFiles\Aufgabe3.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\WISEM18\Semesterarbeit\Aufgabe3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Aufgabe3.exe"
	"D:\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Aufgabe3.dir --manifests  -- C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Aufgabe3.dir\objects1.rsp @<<
 /out:Aufgabe3.exe /implib:Aufgabe3.lib /pdb:D:\WISEM18\Semesterarbeit\Aufgabe3\cmake-build-debug\Aufgabe3.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Aufgabe3.dir\build: Aufgabe3.exe

.PHONY : CMakeFiles\Aufgabe3.dir\build

CMakeFiles\Aufgabe3.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Aufgabe3.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Aufgabe3.dir\clean

CMakeFiles\Aufgabe3.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\WISEM18\Semesterarbeit\Aufgabe3 D:\WISEM18\Semesterarbeit\Aufgabe3 D:\WISEM18\Semesterarbeit\Aufgabe3\cmake-build-debug D:\WISEM18\Semesterarbeit\Aufgabe3\cmake-build-debug D:\WISEM18\Semesterarbeit\Aufgabe3\cmake-build-debug\CMakeFiles\Aufgabe3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Aufgabe3.dir\depend

