# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_SOURCE_DIR = /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/build

# Utility rule file for Shaders.

# Include any custom commands dependencies for this target.
include CMakeFiles/Shaders.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Shaders.dir/progress.make

CMakeFiles/Shaders: ../shaders/point_light.frag.spv
CMakeFiles/Shaders: ../shaders/point_light.vert.spv
CMakeFiles/Shaders: ../shaders/simple_shader.frag.spv
CMakeFiles/Shaders: ../shaders/simple_shader.vert.spv

../shaders/point_light.frag.spv: ../shaders/point_light.frag
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../shaders/point_light.frag.spv"
	/usr/bin/glslangValidator -V /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/shaders/point_light.frag -o /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/shaders/point_light.frag.spv

../shaders/point_light.vert.spv: ../shaders/point_light.vert
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating ../shaders/point_light.vert.spv"
	/usr/bin/glslangValidator -V /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/shaders/point_light.vert -o /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/shaders/point_light.vert.spv

../shaders/simple_shader.frag.spv: ../shaders/simple_shader.frag
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating ../shaders/simple_shader.frag.spv"
	/usr/bin/glslangValidator -V /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/shaders/simple_shader.frag -o /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/shaders/simple_shader.frag.spv

../shaders/simple_shader.vert.spv: ../shaders/simple_shader.vert
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating ../shaders/simple_shader.vert.spv"
	/usr/bin/glslangValidator -V /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/shaders/simple_shader.vert -o /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/shaders/simple_shader.vert.spv

Shaders: CMakeFiles/Shaders
Shaders: ../shaders/point_light.frag.spv
Shaders: ../shaders/point_light.vert.spv
Shaders: ../shaders/simple_shader.frag.spv
Shaders: ../shaders/simple_shader.vert.spv
Shaders: CMakeFiles/Shaders.dir/build.make
.PHONY : Shaders

# Rule to build all files generated by this target.
CMakeFiles/Shaders.dir/build: Shaders
.PHONY : CMakeFiles/Shaders.dir/build

CMakeFiles/Shaders.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Shaders.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Shaders.dir/clean

CMakeFiles/Shaders.dir/depend:
	cd /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/build /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/build /home/pxrcelain/Desktop/vulkan-template/littleVulkanEngine/build/CMakeFiles/Shaders.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Shaders.dir/depend

