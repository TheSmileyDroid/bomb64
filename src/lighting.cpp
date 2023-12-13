#include "../include/lighting.h"

GLfloat light0_pos[] = {20.0f, 20.0f, 60.0f, 1.0f};
GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat gray[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat black[] = {0.01f, 0.01f, 0.01f, 1.0f};

void lighting(void) {
  glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
  glLightfv(GL_LIGHT0, GL_AMBIENT, black);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, gray);
  glLightfv(GL_LIGHT0, GL_SPECULAR, white);

  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}
