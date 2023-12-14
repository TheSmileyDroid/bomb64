#ifndef MATERIAL_H
#define MATERIAL_H

#include "../tiny_obj_loader.h"
#include <GL/gl.h>
#include <array>
#include <iostream>

typedef struct Material {
  float diffuse[3];
  float ambient[3];
  float specular[3];
  float emission[3];
  float shininess;
  int illum;
  float anisotropy;
  std::string diffuse_texname;

  Material(tinyobj::material_t material);

} material_t;

#endif