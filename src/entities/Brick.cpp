/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#include "../../include/entities/Brick.h"

Brick::Brick() {
  model = new Model("assets/brick.obj");
  position = {0.0, 0.0, 0.0};

  aabb = new AABB({-1.0, -0.4, -1.0}, {1.0, 0.4, 1.0}, this);
}

Brick::Brick(glm::vec3 position) {
  model = new Model("assets/brick.obj");
  this->position = position;

  aabb = new AABB({-1.0, -0.4, -1.0}, {1.0, 0.4, 1.0}, this);
}