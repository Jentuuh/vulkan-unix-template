#pragma once

#include "vlt_model.hpp"

// libs
#include <glm/gtc/matrix_transform.hpp>

// std
#include <memory>
#include <unordered_map>

namespace vlt {

struct TransformComponent {
  glm::vec3 translation{};
  glm::vec3 scale{1.f, 1.f, 1.f};
  glm::vec3 rotation{};

  // Matrix corrsponds to Translate * Ry * Rx * Rz * Scale
  // Rotations correspond to Tait-bryan angles of Y(1), X(2), Z(3)
  // https://en.wikipedia.org/wiki/Euler_angles#Rotation_matrix
  glm::mat4 mat4();

  glm::mat3 normalMatrix();
};

struct PointLightComponent {
  float lightIntensity = 1.0f;
};

class VltGameObject {
 public:
  using id_t = unsigned int;
  using Map = std::unordered_map<id_t, VltGameObject>;

  static VltGameObject createGameObject() {
    static id_t currentId = 0;
    return VltGameObject{currentId++};
  }

  static VltGameObject makePointLight(
      float intensity = 10.f, float radius = 0.1f, glm::vec3 color = glm::vec3(1.f));

  VltGameObject(const VltGameObject &) = delete;
  VltGameObject &operator=(const VltGameObject &) = delete;
  VltGameObject(VltGameObject &&) = default;
  VltGameObject &operator=(VltGameObject &&) = default;

  id_t getId() { return id; }

  glm::vec3 color{};
  TransformComponent transform{};

  // Optional pointer components
  std::shared_ptr<VltModel> model{};
  std::unique_ptr<PointLightComponent> pointLight = nullptr;

 private:
  VltGameObject(id_t objId) : id{objId} {}

  id_t id;
};
}  // namespace vlt
