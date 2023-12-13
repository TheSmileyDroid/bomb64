#ifndef ENTITY_H
#define ENTITY_H

#include "Model.h"

class AABB {
public:
  AABB(glm::vec3 min, glm::vec3 max) : min(min), max(max) {}
  glm::vec3 min;
  glm::vec3 max;

  bool checkCollision(const AABB &other) const {
    return (min.x <= other.max.x && max.x >= other.min.x) &&
           (min.y <= other.max.y && max.y >= other.min.y) &&
           (min.z <= other.max.z && max.z >= other.min.z);
  }

  bool checkCollision(const glm::vec3 &point) const {
    return (point.x >= min.x && point.x <= max.x) &&
           (point.y >= min.y && point.y <= max.y) &&
           (point.z >= min.z && point.z <= max.z);
  }

  glm::vec3 getCenter() const { return (min + max) / 2.0f; }

  glm::vec3 getHalfSize() const { return (max - min) / 2.0f; }

  void translate(const glm::vec3 &translation) {
    min += translation;
    max += translation;
  }

  void scale(const glm::vec3 &scale) {
    min *= scale;
    max *= scale;
  }
};

class Entity {
public:
  Entity();
  virtual ~Entity() {}

  virtual void update();
  virtual void draw();
  std::string name;

  Model *model;

  AABB *aabb;

  glm::vec3 position;
  glm::vec3 dir;
  glm::vec3 up;
  glm::vec3 right;
};

#endif // ENTITY_H