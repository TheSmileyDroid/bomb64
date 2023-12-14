/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#ifndef OBJLOADER_H
#define OBJLOADER_H

#include "entities/Material.h"
#include "triangle.h"
#include <array>
#include <cstring>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>

/**
 * @brief Loads an OBJ file and extracts the vertices, texture coordinates,
 * normals, materials, triangles, and colors.
 *
 * @param path The path to the OBJ file.
 * @param out_vertices The vector to store the extracted vertices.
 * @param out_uvs The vector to store the extracted texture coordinates.
 * @param out_normals The vector to store the extracted normals.
 * @param out_materials The vector to store the extracted materials.
 * @param out_triangles The vector to store the extracted triangles.
 * @param out_colors The vector to store the extracted colors.
 * @return true if the OBJ file was successfully loaded and parsed, false
 * otherwise.
 */
bool loadOBJ(const char *path, std::vector<glm::vec3> &out_vertices,
             std::vector<glm::vec2> &out_uvs,
             std::vector<glm::vec3> &out_normals,
             std::vector<material_t> &out_materials,
             std::vector<Triangle> &out_triangles,
             std::vector<glm::vec3> &out_colors);

#endif