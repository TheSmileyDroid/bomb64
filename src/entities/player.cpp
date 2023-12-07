#include "../../include/entities/player.h"

Player::Player(void) {
  position[0] = 0.0;
  position[1] = 0.0;
  position[2] = 0.0;
}

void Player::draw(void) {
  GLfloat shininess = 50.0;
  GLfloat diffuse[4];
  GLfloat specular[4];
  diffuse[0] = 0.2;
  diffuse[1] = 0.2;
  diffuse[2] = 0.2;
  diffuse[3] = 1.0;
  specular[0] = 1.0;
  specular[1] = 1.0;
  specular[2] = 1.0;
  specular[3] = 1.0;

  glBegin(GL_TRIANGLES);
  for (auto triangle = triangles.begin(); triangle != triangles.end();
       ++triangle) {
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, diffuse);
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

bool Player::load_model(void) {
  bool res = loadOBJ("assets/bomb64.obj", vertices, uvs, normals, materials,
                     triangles);
  if (!res) {
    std::cout << "Error loading model" << std::endl;
  } else {
    std::cout << "Model loaded" << std::endl;
  }
  return res;
}

void Player::update(void) {}

void Player::playerCamera(void) {
  float cameraPos[3];
  cameraPos[0] = position[0] + dir[0] * camera_distance;
  cameraPos[1] = position[1] + dir[1] * camera_distance;
  cameraPos[2] = position[2] + dir[2] * camera_distance;

  gluLookAt(position[0], position[1], position[2], // Position of camera
            position[0] + dir[0], position[1] + dir[1],
            position[2] + dir[2], // Direction of camera
            up[0], up[1], up[2]   // Up vector
  );
}
