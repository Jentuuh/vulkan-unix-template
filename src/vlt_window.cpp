#include "vlt_window.hpp"

// std
#include <stdexcept>

namespace vlt {

VltWindow::VltWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
  initWindow();
}

VltWindow::~VltWindow() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

void VltWindow::initWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

  window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
  glfwSetWindowUserPointer(window, this);
  glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void VltWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
  if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
    throw std::runtime_error("failed to craete window surface");
  }
}

void VltWindow::framebufferResizeCallback(GLFWwindow *window, int width, int height) {
  auto vltWindow = reinterpret_cast<VltWindow *>(glfwGetWindowUserPointer(window));
  vltWindow->framebufferResized = true;
  vltWindow->width = width;
  vltWindow->height = height;
}

}  // namespace vlt
