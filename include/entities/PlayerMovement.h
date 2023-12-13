#include <glm/glm.hpp>

#include "./InputHandler.h"

class PlayerMovement {
public:
  void updatePosition(const InputHandler &inputHandler);
  glm::vec3 getPosition() const;

private:
  glm::vec3 position = {0.0, 100.0, 0.0};
  glm::vec3 velocity = {0.0f, 0.0f, 0.0f};
};