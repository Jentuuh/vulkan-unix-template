#pragma once

#include "vlt_camera.hpp"
#include "vlt_device.hpp"
#include "vlt_frame_info.hpp"
#include "vlt_game_object.hpp"
#include "vlt_pipeline.hpp"

// std
#include <memory>
#include <vector>

namespace vlt {
class SimpleRenderSystem {
 public:
  SimpleRenderSystem(
      VltDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
  ~SimpleRenderSystem();

  SimpleRenderSystem(const SimpleRenderSystem &) = delete;
  SimpleRenderSystem &operator=(const SimpleRenderSystem &) = delete;

  void renderGameObjects(FrameInfo &frameInfo);

 private:
  void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
  void createPipeline(VkRenderPass renderPass);

  VltDevice &vltDevice;

  std::unique_ptr<VltPipeline> vltPipeline;
  VkPipelineLayout pipelineLayout;
};
}  // namespace vlt
