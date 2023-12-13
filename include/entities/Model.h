#ifndef MODEL_H
#define MODEL_H

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
#include <vector>

#include "../delta.h"
#include "../objloader.h"
#include "../triangle.h"

class Model {
private:
  const char *filename;

public:
  Model();
  Model(const char *filename);
  void draw();
  bool load_model();

  std::vector<glm::vec3> vertices;
  std::vector<glm::vec2> uvs;
  std::vector<glm::vec3> normals;
  std::vector<glm::vec3> colors;
  std::vector<material_t> materials;
  std::vector<Triangle> triangles;
};

#endif