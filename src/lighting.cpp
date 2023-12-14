/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#include "../include/lighting.h"

GLfloat light0_pos[] = {20.0f, 20.0f, 30.0f, 1.0f};
GLfloat light1_pos[] = {-10.0f, 30.0f, 20.0f, 1.0f};
GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat gray[] = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat black[] = {0.04f, 0.04f, 0.05f, 1.0f};

void lighting(void) {
  glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
  glLightfv(GL_LIGHT0, GL_AMBIENT, black);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, gray);
  glLightfv(GL_LIGHT0, GL_SPECULAR, white);

  glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
  glLightfv(GL_LIGHT1, GL_AMBIENT, black);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, gray);
  glLightfv(GL_LIGHT1, GL_SPECULAR, white);

  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);

  glShadeModel(GL_SMOOTH);

  glEnable(GL_NORMALIZE);
}
