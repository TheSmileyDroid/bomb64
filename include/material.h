#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/gl.h>
#include <array>
#include <iostream>

typedef struct Material {
  float diffuse[3];
  float ambient[3];
  float specular[3];
  float emission[3];
  float shininess;

  Material(float _diffuse[3], float _ambient[3], float _specular[3],
           float _emission[3], float _shininess) {
    std::cout << "Material" << std::endl;
    diffuse[0] = _diffuse[0];
    diffuse[1] = _diffuse[1];
    diffuse[2] = _diffuse[2];
    ambient[0] = _ambient[0];
    ambient[1] = _ambient[1];
    ambient[2] = _ambient[2];
    specular[0] = _specular[0];
    specular[1] = _specular[1];
    specular[2] = _specular[2];
    emission[0] = _emission[0];
    emission[1] = _emission[1];
    emission[2] = _emission[2];
    shininess = _shininess;
  }
} material_t;

#endif