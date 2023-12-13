#include "../../include/entities/Model.h"

Model::Model(const char *filename) {
  this->filename = filename;
  load_model();
}

Model::Model() { this->filename = ""; }

bool Model::load_model() {
  bool res = loadOBJ(filename, vertices, uvs, normals, materials, triangles);
  if (!res) {
    printf("Error loading model\n");
  } else {
    printf("Model loaded\n");
  }
  return res;
}

void Model::draw() {
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
    glNormal3f(normals[triangle->normals[0]].x, normals[triangle->normals[0]].y,
               normals[triangle->normals[0]].z);
    glVertex3f(vertices[triangle->vertices[0]].x,
               vertices[triangle->vertices[0]].y,
               vertices[triangle->vertices[0]].z);

    glNormal3f(normals[triangle->normals[1]].x, normals[triangle->normals[1]].y,
               normals[triangle->normals[1]].z);
    glVertex3f(vertices[triangle->vertices[1]].x,
               vertices[triangle->vertices[1]].y,
               vertices[triangle->vertices[1]].z);

    glNormal3f(normals[triangle->normals[2]].x, normals[triangle->normals[2]].y,
               normals[triangle->normals[2]].z);
    glVertex3f(vertices[triangle->vertices[2]].x,
               vertices[triangle->vertices[2]].y,
               vertices[triangle->vertices[2]].z);
  }
  glEnd();
}