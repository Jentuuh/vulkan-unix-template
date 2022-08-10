#pragma once

#include "vlt_device.hpp"

// std
#include <memory>
#include <unordered_map>
#include <vector>

namespace vlt {

class VltDescriptorSetLayout {
 public:
  class Builder {
   public:
    Builder(VltDevice &vltDevice) : vltDevice{vltDevice} {}

    Builder &addBinding(
        uint32_t binding,
        VkDescriptorType descriptorType,
        VkShaderStageFlags stageFlags,
        uint32_t count = 1);
    std::unique_ptr<VltDescriptorSetLayout> build() const;

   private:
    VltDevice &vltDevice;
    std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> bindings{};
  };

  VltDescriptorSetLayout(
      VltDevice &vltDevice, std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> bindings);
  ~VltDescriptorSetLayout();
  VltDescriptorSetLayout(const VltDescriptorSetLayout &) = delete;
  VltDescriptorSetLayout &operator=(const VltDescriptorSetLayout &) = delete;

  VkDescriptorSetLayout getDescriptorSetLayout() const { return descriptorSetLayout; }

 private:
  VltDevice &vltDevice;
  VkDescriptorSetLayout descriptorSetLayout;
  std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> bindings;

  friend class VltDescriptorWriter;
};

class VltDescriptorPool {
 public:
  class Builder {
   public:
    Builder(VltDevice &vltDevice) : vltDevice{vltDevice} {}

    Builder &addPoolSize(VkDescriptorType descriptorType, uint32_t count);
    Builder &setPoolFlags(VkDescriptorPoolCreateFlags flags);
    Builder &setMaxSets(uint32_t count);
    std::unique_ptr<VltDescriptorPool> build() const;

   private:
    VltDevice &vltDevice;
    std::vector<VkDescriptorPoolSize> poolSizes{};
    uint32_t maxSets = 1000;
    VkDescriptorPoolCreateFlags poolFlags = 0;
  };

  VltDescriptorPool(
      VltDevice &vltDevice,
      uint32_t maxSets,
      VkDescriptorPoolCreateFlags poolFlags,
      const std::vector<VkDescriptorPoolSize> &poolSizes);
  ~VltDescriptorPool();
  VltDescriptorPool(const VltDescriptorPool &) = delete;
  VltDescriptorPool &operator=(const VltDescriptorPool &) = delete;

  bool allocateDescriptor(
      const VkDescriptorSetLayout descriptorSetLayout, VkDescriptorSet &descriptor) const;

  void freeDescriptors(std::vector<VkDescriptorSet> &descriptors) const;

  void resetPool();

 private:
  VltDevice &vltDevice;
  VkDescriptorPool descriptorPool;

  friend class VltDescriptorWriter;
};

class VltDescriptorWriter {
 public:
  VltDescriptorWriter(VltDescriptorSetLayout &setLayout, VltDescriptorPool &pool);

  VltDescriptorWriter &writeBuffer(uint32_t binding, VkDescriptorBufferInfo *bufferInfo);
  VltDescriptorWriter &writeImage(uint32_t binding, VkDescriptorImageInfo *imageInfo);

  bool build(VkDescriptorSet &set);
  void overwrite(VkDescriptorSet &set);

 private:
  VltDescriptorSetLayout &setLayout;
  VltDescriptorPool &pool;
  std::vector<VkWriteDescriptorSet> writes;
};

}  // namespace vlt
