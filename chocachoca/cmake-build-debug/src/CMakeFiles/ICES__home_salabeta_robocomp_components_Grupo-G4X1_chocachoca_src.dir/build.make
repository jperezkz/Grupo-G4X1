# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/126/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/126/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug

# Utility rule file for ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.

# Include the progress variables for this target.
include src/CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/progress.make

ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src: src/CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating CommonBehavior.ice from /opt/robocomp//interfaces/IDSLs/CommonBehavior.idsl"
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src && robocompdsl /opt/robocomp//interfaces/IDSLs/CommonBehavior.idsl /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/src/CommonBehavior.ice
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src && robocompdsl /opt/robocomp//interfaces/IDSLs/CommonBehavior.idsl CommonBehavior.ice
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating DifferentialRobot.ice from /opt/robocomp//interfaces/IDSLs/DifferentialRobot.idsl"
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src && robocompdsl /opt/robocomp//interfaces/IDSLs/DifferentialRobot.idsl /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/src/DifferentialRobot.ice
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src && robocompdsl /opt/robocomp//interfaces/IDSLs/DifferentialRobot.idsl DifferentialRobot.ice
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating GenericBase.ice from /opt/robocomp//interfaces/IDSLs/GenericBase.idsl"
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src && robocompdsl /opt/robocomp//interfaces/IDSLs/GenericBase.idsl /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/src/GenericBase.ice
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src && robocompdsl /opt/robocomp//interfaces/IDSLs/GenericBase.idsl GenericBase.ice
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating Laser.ice from /opt/robocomp//interfaces/IDSLs/Laser.idsl"
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src && robocompdsl /opt/robocomp//interfaces/IDSLs/Laser.idsl /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/src/Laser.ice
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src && robocompdsl /opt/robocomp//interfaces/IDSLs/Laser.idsl Laser.ice
.PHONY : ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src

# Rule to build all files generated by this target.
src/CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/build: ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src

.PHONY : src/CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/build

src/CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/clean:
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/clean

src/CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/depend:
	cd /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/src /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src /home/salabeta/robocomp/components/Grupo-G4X1/chocachoca/cmake-build-debug/src/CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ICES__home_salabeta_robocomp_components_Grupo-G4X1_chocachoca_src.dir/depend

