#pragma once

#include "vlt_device.hpp"
#include "vlt_swap_chain.hpp"
#include "vlt_window.hpp"

// std
#include <cassert>
#include <memory>
#include <vector>

namespace vlt {
class VltRenderer {
 public:
  VltRenderer(VltWindow &window, VltDevice &device);
  ~VltRenderer();

  VltRenderer(const VltRenderer &) = delete;
  VltRenderer &operator=(const VltRenderer &) = delete;

  VkRenderPass getSwapChainRenderPass() const { return vltSwapChain->getRenderPass(); }
  float getAspectRatio() const { return vltSwapChain->extentAspectRatio(); }
  bool isFrameInProgress() const { return isFrameStarted; }

  VkCommandBuffer getCurrentCommandBuffer() const {
    assert(isFrameStarted && "Cannot get command buffer when frame not in progress");
    return commandBuffers[currentFrameIndex];
  }

  int getFrameIndex() const {
    assert(isFrameStarted && "Cannot get frame index when frame not in progress");
    return currentFrameIndex;
  }

  VkCommandBuffer beginFrame();
  void endFrame();
  void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
  void endSwapChainRenderPass(VkCommandBuffer commandBuffer);

 private:
  void createCommandBuffers();
  void freeCommandBuffers();
  void recreateSwapChain();

  VltWindow &vltWindow;
  VltDevice &vltDevice;
  std::unique_ptr<VltSwapChain> vltSwapChain;
  std::vector<VkCommandBuffer> commandBuffers;

  uint32_t currentImageIndex;
  int currentFrameIndex{0};
  bool isFrameStarted{false};
};
}  // namespace vlt
