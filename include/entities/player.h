#ifndef PLAYER_H
#define PLAYER_H

#include <GL/glut.h>
#include <SDL2/SDL_keyboard.h>

#include <glm/fwd.hpp>
#include <glm/vec3.hpp>
#include <math.h>
#include <stdbool.h>
#include <vector>

#include "../objloader.h"
#include "../triangle.h"

class Player {
public:
  Player(void);
  float position[3] = {0.0, 0.0, 0.0};
  float dir[3] = {0.0, 0.0, 1.0};
  float up[3] = {0.0, 1.0, 0.0};
  float camera_distance = 5.0;
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec2> uvs;
  std::vector<glm::vec3> normals;
  std::vector<glm::vec3> colors;
  std::vector<material_t> materials;
  std::vector<Triangle> triangles;

  void draw(void);

  void update(void);

  bool load_model(void);

  void playerCamera(void);

  void playerCameraMovementKeyDown(SDL_Keysym *key);

  void playerCameraMovementKeyUp(SDL_Keysym *key);
};

extern Player player;

#endif