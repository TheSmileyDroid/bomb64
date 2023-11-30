#include "../include/objloader.h"
#ifndef TINYOBJLOADER_IMPLEMENTATION
#define TINYOBJLOADER_IMPLEMENTATION
#include "../include/tiny_obj_loader.h"
#endif

bool loadOBJ(const char *path, std::vector<glm::vec3> &out_vertices,
             std::vector<glm::vec2> &out_uvs,
             std::vector<glm::vec3> &out_normals,
             std::vector<Triangle> &out_triangles) {
  std::string inputfile = path;
  tinyobj::ObjReaderConfig reader_config;
  reader_config.mtl_search_path = "./assets/";
  reader_config.triangulate = true;

  tinyobj::ObjReader reader;

  if (!reader.ParseFromFile(inputfile, reader_config)) {
    if (!reader.Error().empty()) {
      std::cerr << "TinyObjReader: " << reader.Error();
    }
    exit(1);
  }

  std::cout << "TinyObjReader: " << inputfile << std::endl;

  if (!reader.Warning().empty()) {
    std::cout << "TinyObjReader: " << reader.Warning();
  }

  auto &attrib = reader.GetAttrib();
  auto &shapes = reader.GetShapes();
  // auto &materials = reader.GetMaterials();

  std::cout << "Number of vertices: " << attrib.vertices.size() / 3
            << std::endl;
  std::cout << "Number of normals: " << attrib.normals.size() / 3 << std::endl;
  std::cout << "Number of texcoords: " << attrib.texcoords.size() / 2
            << std::endl;

  out_vertices.reserve(attrib.vertices.size() / 3);

  for (size_t vec_start = 0; vec_start < attrib.vertices.size();
       vec_start += 3) {
    out_vertices.emplace_back(attrib.vertices[vec_start],
                              attrib.vertices[vec_start + 1],
                              attrib.vertices[vec_start + 2]);
  }

  for (size_t tex_start = 0; tex_start < attrib.texcoords.size();
       tex_start += 2) {
    out_uvs.emplace_back(attrib.texcoords[tex_start],
                         attrib.texcoords[tex_start + 1]);
  }

  for (size_t norm_start = 0; norm_start < attrib.normals.size();
       norm_start += 3) {
    out_normals.emplace_back(attrib.normals[norm_start],
                             attrib.normals[norm_start + 1],
                             attrib.normals[norm_start + 2]);
  }

  for (auto shape = shapes.begin(); shape < shapes.end(); ++shape) {
    const std::vector<tinyobj::index_t> &indices = shape->mesh.indices;
    const std::vector<int> &material_ids = shape->mesh.material_ids;

    for (size_t index = 0; index < material_ids.size(); ++index) {
      // offset by 3 because values are grouped as vertex/normal/texture
      out_triangles.push_back(Triangle(
          {indices[3 * index].vertex_index, indices[3 * index + 1].vertex_index,
           indices[3 * index + 2].vertex_index},
          {indices[3 * index].normal_index, indices[3 * index + 1].normal_index,
           indices[3 * index + 2].normal_index},
          {indices[3 * index].texcoord_index,
           indices[3 * index + 1].texcoord_index,
           indices[3 * index + 2].texcoord_index},
          material_ids[index]));
    }
  }

  std::cout << "Number of vertices: " << out_vertices.size() << std::endl;

  return true;
}