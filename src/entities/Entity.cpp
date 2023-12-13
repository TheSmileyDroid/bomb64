#include "../../include/entities/Entity.h"

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
