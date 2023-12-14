#ifndef ENTITY_H
#define ENTITY_H

#include "Model.h"

class Entity;

class AABB {
public:
  AABB(glm::vec3 min, glm::vec3 max, Entity *entity = nullptr)
      : min(min), max(max), entity(entity) {}
  glm::vec3 min;
  glm::vec3 max;
  Entity *entity;

  bool checkCollision(const AABB &other) const;

  bool checkCollision(const glm::vec3 &point) const;

  glm::vec3 getGlobalCenter() const;

  glm::vec3 getCenter() const { return (min + max) / 2.0f; }

  glm::vec3 getHalfSize() const { return (max - min) / 2.0f; }

  AABB translate(const glm::vec3 &translation) const {
    return AABB(min + translation, max + translation);
  }

  AABB scale(const glm::vec3 &scale) const {
    return AABB(min * scale, max * scale);
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

extern std::vector<Entity *> entities;

#endif // ENTITY_H