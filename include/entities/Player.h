#ifndef PLAYER_H
#define PLAYER_H

#include <GL/gl.h>
#include <GL/glut.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <algorithm>
#include <cstdio>
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include <glm/geometric.hpp>
#include <glm/vec3.hpp>
#include <math.h>
#include <stdbool.h>
#include <string>
#include <vector>

#include "../delta.h"
#include "../triangle.h"
#include "Entity.h"
#include "InputHandler.h"

class Player : public Entity, public IPlayer {
public:
  Player(void);
  void input(SDL_Event *event);
  void update() override;
  void draw() override;
  void rotateMotion(int motionX, int motionY) override;
  void camera();
  bool willCollide(glm::vec3 position);
  bool isOnGround();
  InputHandler *input_handler;

  double speed;
  double gravity;
  float sensitivityX;
  float sensitivityY;
  float yaw;
  float pitch;
  glm::vec3 velocity;
  glm::vec3 target_velocity;
  double camera_distance;
};

#endif