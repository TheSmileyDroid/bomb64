/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#include "../../include/entities/Ground.h"

Ground::Ground() {
  model = new Model("assets/ground.obj");
  position = {0.0, -1.0, 0.0};
  name = "Ground";

  aabb = new AABB({-90.0, -0.25, -90.0}, {90.0, 0.25, 90.0}, this);
}

void Ground::draw() {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  model->draw();
  glPopMatrix();
}

void Ground::update() {}
