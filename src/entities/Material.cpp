/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#include "../../include/entities/Material.h"

Material::Material(tinyobj::material_t material) {
  this->diffuse[0] = material.diffuse[0];
  this->diffuse[1] = material.diffuse[1];
  this->diffuse[2] = material.diffuse[2];
  this->ambient[0] = material.ambient[0];
  this->ambient[1] = material.ambient[1];
  this->ambient[2] = material.ambient[2];
  this->specular[0] = material.specular[0];
  this->specular[1] = material.specular[1];
  this->specular[2] = material.specular[2];
  this->emission[0] = material.emission[0];
  this->emission[1] = material.emission[1];
  this->emission[2] = material.emission[2];
  this->shininess = material.shininess;
  this->illum = material.illum;
  this->anisotropy = material.anisotropy;
  this->diffuse_texname = material.diffuse_texname;
}
