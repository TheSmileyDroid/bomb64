#include "../../include/entities/Ground.h"

Ground::Ground() {
  model = new Model("assets/ground.obj");
  position = {0.0, -1.0, 0.0};
  name = "Ground";

  aabb = new AABB({-1.0, -1.0, -1.0}, {1.0, 1.0, 1.0});
}

void Ground::draw() {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  model->draw();
  glPopMatrix();
}

void Ground::update() {}
