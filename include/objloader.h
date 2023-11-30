#ifndef OBJLOADER_H
#define OBJLOADER_H

#include "face.h"
#include <array>
#include <cstring>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>

bool loadOBJ(const char *path, std::vector<glm::vec3> &out_vertices,
             std::vector<glm::vec2> &out_uvs,
             std::vector<glm::vec3> &out_normals,
             std::vector<Triangle> &out_triangles);

#endif