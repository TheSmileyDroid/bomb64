#include "../include/lighting.h"

void lighting(void) {
  glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
  glLightfv(GL_LIGHT0, GL_AMBIENT, black);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
  glLightfv(GL_LIGHT0, GL_SPECULAR, white);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}
