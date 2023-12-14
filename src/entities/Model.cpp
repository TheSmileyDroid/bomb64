#include "../../include/entities/Model.h"

std::map<std::string, GLuint> textures;

Model::Model(const char *filename) {
  this->filename = filename;
  load_model();

  for (auto material = materials.begin(); material != materials.end();
       ++material) {
    if (material->diffuse_texname != "") {
      std::string textureFilename =
          std::string("assets/") + material->diffuse_texname;

      if (textures.find(textureFilename) != textures.end()) {
        texture = textures[textureFilename];
        break;
      }
      load_texture(textureFilename.c_str());
      break;
    }
  }
}

Model::Model() { this->filename = ""; }

bool Model::load_model() {
  bool res =
      loadOBJ(filename, vertices, uvs, normals, materials, triangles, colors);
  if (!res) {
    printf("Error loading model\n");
  } else {
    printf("Model loaded\n");
  }
  return res;
}

void Model::load_texture(const char *filename) {
  SDL_Surface *surface = SDL_LoadBMP(filename);
  if (surface == NULL) {
    printf("Error loading texture\n");
    return;
  }
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB, surface->w, surface->h, 0, GL_BGR,
               GL_UNSIGNED_BYTE, surface->pixels);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  printf("Texture %s loaded with id %d\n", filename, texture);
  textures[filename] = texture;
}

void Model::draw() {
  if (texture != 0) {
    glBindTexture(GL_TEXTURE_2D, texture);
  }
  glBegin(GL_TRIANGLES);
  for (auto triangle = triangles.begin(); triangle != triangles.end();
       ++triangle) {
    GLfloat shininess = materials[triangle->material].shininess;
    GLfloat ambient[4];
    ambient[0] = materials[triangle->material].ambient[0];
    ambient[1] = materials[triangle->material].ambient[1];
    ambient[2] = materials[triangle->material].ambient[2];
    ambient[3] = 1.0;
    GLfloat diffuse[4];
    GLfloat specular[4];
    diffuse[0] = materials[triangle->material].diffuse[0];
    diffuse[1] = materials[triangle->material].diffuse[1];
    diffuse[2] = materials[triangle->material].diffuse[2];
    diffuse[3] = 1.0;
    specular[0] = materials[triangle->material].specular[0];
    specular[1] = materials[triangle->material].specular[1];
    specular[2] = materials[triangle->material].specular[2];
    specular[3] = 1.0;
    GLfloat emission[4];
    emission[0] = materials[triangle->material].emission[0];
    emission[1] = materials[triangle->material].emission[1];
    emission[2] = materials[triangle->material].emission[2];
    emission[3] = 1.0;

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_EMISSION, emission);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    for (int i = 0; i < 3; i++) {
      glTexCoord2f(uvs[triangle->uvs[i]].x, uvs[triangle->uvs[i]].y);
      glNormal3f(normals[triangle->normals[i]].x,
                 normals[triangle->normals[i]].y,
                 normals[triangle->normals[i]].z);
      glVertex3f(vertices[triangle->vertices[i]].x,
                 vertices[triangle->vertices[i]].y,
                 vertices[triangle->vertices[i]].z);
    }
  }
  glEnd();
}