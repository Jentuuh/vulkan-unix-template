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
class PointLightSystem {
 public:
  PointLightSystem(
      VltDevice &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
  ~PointLightSystem();

  PointLightSystem(const PointLightSystem &) = delete;
  PointLightSystem &operator=(const PointLightSystem &) = delete;

  void update(FrameInfo &frameInfo, GlobalUbo &ubo);
  void render(FrameInfo &frameInfo);

 private:
  void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
  void createPipeline(VkRenderPass renderPass);

  VltDevice &vltDevice;

  std::unique_ptr<VltPipeline> vltPipeline;
  VkPipelineLayout pipelineLayout;
};
}  // namespace vlt
