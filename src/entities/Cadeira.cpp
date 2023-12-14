#include "../../include/entities/Cadeira.h"

Cadeira::Cadeira() {
  model = new Model("assets/cadeira.obj");
  position = {10.0, -1.0, 5.0};

  aabb = new AABB({-1.0, 0.0, -1.0}, {1.0, 2.0, 1.0}, this);
}