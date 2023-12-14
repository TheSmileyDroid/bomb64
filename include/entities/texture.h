#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>
#include <GL/glut.h>

class Texture {
private:
  const char *filename;

public:
  Texture();
  Texture(const char *filename);
  void draw();
  bool load_texture();
  GLuint texture_id;
};

#endif