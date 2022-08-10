#pragma once

#include "vlt_descriptors.hpp"
#include "vlt_device.hpp"
#include "vlt_game_object.hpp"
#include "vlt_renderer.hpp"
#include "vlt_window.hpp"

// std
#include <memory>
#include <vector>

namespace vlt {
class App {
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  App();
  ~App();

  App(const App &) = delete;
  App &operator=(const App &) = delete;

  void run();

 private:
  void loadGameObjects();

  VltWindow vltWindow{WIDTH, HEIGHT, "Vulkan Template"};
  VltDevice vltDevice{vltWindow};
  VltRenderer vltRenderer{vltWindow, vltDevice};

  // note: order of declarations matters
  std::unique_ptr<VltDescriptorPool> globalPool{};
  VltGameObject::Map gameObjects;
};
}  // namespace vlt
