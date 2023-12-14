#include "../../include/entities/Entity.h"

std::vector<Entity *> entities;

bool AABB::checkCollision(const AABB &other) const {
  if (entity != nullptr && other.entity != nullptr &&
      entity->name == other.entity->name) {
    return false;
  }
  AABB a = translate(entity->position);
  AABB b = other.translate(other.entity->position);

  return (a.max.x >= b.min.x && a.min.x <= b.max.x) &&
         (a.max.y >= b.min.y && a.min.y <= b.max.y) &&
         (a.max.z >= b.min.z && a.min.z <= b.max.z);
}

bool AABB::checkCollision(const glm::vec3 &point) const {
  return (point.x >= min.x && point.x <= max.x) &&
         (point.y >= min.y && point.y <= max.y) &&
         (point.z >= min.z && point.z <= max.z);
}

glm::vec3 AABB::getGlobalCenter() const {
  return entity->position + getCenter();
}

Entity::Entity() {
  position = {0.0, 0.0, 0.0};
  dir = {0.0, 0.0, 1.0};
  up = {0.0, 1.0, 0.0};
  right = {1.0, 0.0, 0.0};

  name = "Entity";

  aabb = new AABB({-1.0, -1.0, -1.0}, {1.0, 1.0, 1.0});

  model = new Model();
}

void Entity::update() {}

void Entity::draw() {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  float angle = atan2(dir.z, dir.x) - M_PI / 2.0f;
  glRotatef(-angle * 180.0 / M_PI, 0.0, 1.0, 0.0);
  model->draw();
  glPopMatrix();
}
