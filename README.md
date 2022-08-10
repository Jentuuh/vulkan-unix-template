# vulkan-linux-template
A starter template for Vulkan projects on the Linux operating system. This template is based on [Brendan Galea's ](https://github.com/blurrypiano/littleVulkanEngine) excellent tutorial series on Vulkan.

## Contents
The template has already set up the following things: 

* Physical + logical device setup
* Swapchain creation and management
* Pipeline creation and management (properties are rather default)
* Descriptor set creation and management
* Buffer helper object to simplify buffer operations
* Window creation and management
* Loading of game objects (using tinyobjloader, only supports .obj files though)
* Simple camera movement through keyboard commands (WASD, QE, arrows)

## Building
First, clone the repository and run the following commands: 
```
  sudo apt update
  sudo apt install vulkan-tools
  sudo apt install libvulkan-dev
  sudo apt install vulkan-validationlayers-dev spirv-tools
  sudo apt install libglfw3-dev
  sudo apt install libglm-dev
  sudo apt install glslang-tools
  sudo apt install cmake
```
This will install the necessary dependencies.
To build, run the following command in the root directory of this repository:
```
./build.sh
```
