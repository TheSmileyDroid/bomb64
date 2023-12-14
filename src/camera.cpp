/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#include "../include/camera.h"
#include "../include/delta.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#define UNUSED(x) (void)(x)

// Variáveis globais para a posição e direção da câmera
float camera_pos[3] = {0.0, 0.0, 0.0};
float camera_dir[3] = {0.0, 0.0, 1.0};
float camera_up[3] = {0.0, 1.0, 0.0};
float camera_right[3] = {0.0, 0.0, 0.0};
float lastMotion[2] = {0.0, 0.0};
bool isWarping = false;
bool forward = false;
bool backward = false;
bool left = false;
bool right = false;
bool up = false;
bool down = false;

void cameraRight(void) {
  camera_right[0] = camera_up[1] * camera_dir[2] - camera_up[2] * camera_dir[1];
  camera_right[1] = camera_up[2] * camera_dir[0] - camera_up[0] * camera_dir[2];
  camera_right[2] = camera_up[0] * camera_dir[1] - camera_up[1] * camera_dir[0];
}

void camera(void) {
  gluLookAt(camera_pos[0], camera_pos[1], camera_pos[2],
            camera_pos[0] + camera_dir[0], camera_pos[1] + camera_dir[1],
            camera_pos[2] + camera_dir[2], camera_up[0], camera_up[1],
            camera_up[2]);
  cameraRight();
}

void cameraMovementKeyDown(SDL_Keysym *key) {
  switch (key->sym) {
  case SDLK_w:
    forward = true;
    break;
  case SDLK_s:
    backward = true;
    break;
  case SDLK_a:
    left = true;
    break;
  case SDLK_d:
    right = true;
    break;
  case SDLK_LSHIFT:
    down = true;
    break;
  case SDLK_SPACE:
    up = true;
    break;
  default:
    break;
  }
}

void cameraMovementKeyUp(SDL_Keysym *key) {
  switch (key->sym) {
  case SDLK_w:
    forward = false;
    break;
  case SDLK_s:
    backward = false;
    break;
  case SDLK_a:
    left = false;
    break;
  case SDLK_d:
    right = false;
    break;
  case SDLK_LSHIFT:
    down = false;
    break;
  case SDLK_SPACE:
    up = false;
    break;
  default:
    break;
  }
}

void cameraUpdate(void) {
  float speed = 0.01f * deltaTime;
  if (forward) {
    camera_pos[0] += camera_dir[0] * speed;
    camera_pos[1] += camera_dir[1] * speed;
    camera_pos[2] += camera_dir[2] * speed;
  }
  if (backward) {
    camera_pos[0] -= camera_dir[0] * speed;
    camera_pos[1] -= camera_dir[1] * speed;
    camera_pos[2] -= camera_dir[2] * speed;
  }
  if (left) {
    camera_pos[0] += camera_right[0] * speed;
    camera_pos[1] += camera_right[1] * speed;
    camera_pos[2] += camera_right[2] * speed;
  }
  if (right) {
    camera_pos[0] -= camera_right[0] * speed;
    camera_pos[1] -= camera_right[1] * speed;
    camera_pos[2] -= camera_right[2] * speed;
  }
  if (up) {
    camera_pos[0] += camera_up[0] * speed;
    camera_pos[1] += camera_up[1] * speed;
    camera_pos[2] += camera_up[2] * speed;
  }
  if (down) {
    camera_pos[0] -= camera_up[0] * speed;
    camera_pos[1] -= camera_up[1] * speed;
    camera_pos[2] -= camera_up[2] * speed;
  }
}

void cameraRotation(int motionX, int motionY) {
  static float sensitivityX = 0.1f;
  static float sensitivityY = 0.1f;
  static float yaw = 0.0f;
  static float pitch = 0.0f;

  yaw += motionX * sensitivityX;
  pitch += -motionY * sensitivityY;

  if (pitch > 89.0f) {
    pitch = 89.0f;
  }
  if (pitch < -89.0f) {
    pitch = -89.0f;
  }

  camera_dir[0] = cos(yaw * M_PI / 180.0f) * cos(pitch * M_PI / 180.0f);
  camera_dir[1] = sin(pitch * M_PI / 180.0f);
  camera_dir[2] = sin(yaw * M_PI / 180.0f) * cos(pitch * M_PI / 180.0f);

  cameraRight();
}
