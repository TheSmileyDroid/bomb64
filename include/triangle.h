/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <array>

/**
 * @brief Represents a triangle in 3D space.
 */
struct Triangle {
  std::array<int, 3> vertices; /**< The vertices of the triangle. */
  std::array<int, 3> normals;  /**< The normals of the triangle. */
  std::array<int, 3> uvs;      /**< The UV coordinates of the triangle. */
  int material;                /**< The material index of the triangle. */

  /**
   * @brief Constructs a Triangle object.
   * @param v The vertices of the triangle.
   * @param n The normals of the triangle.
   * @param uv The UV coordinates of the triangle.
   * @param m The material index of the triangle.
   */
  Triangle(std::array<int, 3> v, std::array<int, 3> n, std::array<int, 3> uv,
           int m)
      : vertices(v), normals(n), uvs(uv), material(m){};
};

#endif