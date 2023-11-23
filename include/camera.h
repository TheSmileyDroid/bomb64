#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>
#include <SDL2/SDL_keyboard.h>

#include <math.h>
#include <stdbool.h>

extern GLfloat camera_pos[3];
extern GLfloat camera_center[3];
extern GLfloat camera_up[3];

void camera();

void cameraMovementKeyUp(SDL_Keysym *key);
void cameraMovementKeyDown(SDL_Keysym *key);

void cameraUpdate();

void cameraRotation(int x, int y);

#endif