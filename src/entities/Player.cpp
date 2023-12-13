#include "../../include/entities/Player.h"

Player::Player() {
  this->model = new Model("assets/bomb64.obj");
  this->name = "Player";
  position = {0.0, 100.0, 0.0};
  speed = 0.01;
  yaw = -90.0f;
  pitch = 0.0f;
  sensitivityX = 0.1f;
  sensitivityY = 0.1f;
  camera_distance = 5.0f;
  gravity = 0.0025f;
  target_velocity = {0.0f, 0.0f, 0.0f};
  velocity = {0.0f, 0.0f, 0.0f};
  dir = {0.0f, 0.0f, -1.0f};
  up = {0.0f, 1.0f, 0.0f};
  right = {1.0f, 0.0f, 0.0f};

  aabb = new AABB({-1.0, -1.0, -1.0}, {1.0, 1.0, 1.0});

  input_handler = new InputHandler();
}

void Player::draw() {
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  float angle = atan2(dir.z, dir.x) - M_PI / 2.0f;
  glRotatef(-angle * 180.0 / M_PI, 0.0, 1.0, 0.0);
  model->draw();
  glPopMatrix();
}

void Player::input(SDL_Event *event) {
  input_handler->handleInput(*this, event);
}

glm::vec3 rotateVector(glm::vec3 vector, float angle) {
  glm::vec3 rotated_vector;
  rotated_vector.x = vector.x * cos(angle) - vector.z * sin(angle);
  rotated_vector.y = vector.y;
  rotated_vector.z = vector.x * sin(angle) + vector.z * cos(angle);
  return rotated_vector;
}

void Player::update(void) {
  glm::vec3 move_direction = {0.0f, 0.0f, 0.0f};
  if (input_handler->moveForward()) {
    move_direction.z += 1.0f;
  }
  if (input_handler->moveBack()) {
    move_direction.z -= 1.0f;
  }
  if (input_handler->moveLeft()) {
    move_direction.x += 1.0f;
  }
  if (input_handler->moveRight()) {
    move_direction.x -= 1.0f;
  }

  if (move_direction.x != 0.0f || move_direction.z != 0.0f) {
    float angle = atan2(dir.z, dir.x) - M_PI / 2.0f;
    move_direction = glm::normalize(move_direction);
    move_direction = rotateVector(move_direction, angle);
  }
  target_velocity.x = move_direction.x * speed * deltaTime;
  target_velocity.z = move_direction.z * speed * deltaTime;

  if (position.y > 0.0) {
    target_velocity.y = target_velocity.y - (gravity * deltaTime);
  } else {
    target_velocity.y = 0.0;
  }

  if (input_handler->performJump() && position.y == 0.0) {
    target_velocity.y = 1.0;
  }

  velocity = target_velocity;

  position.x += velocity.x;
  position.y += velocity.y;
  position.z += velocity.z;
  if (move_direction.x != 0.0f || move_direction.z != 0.0f) {
    printf("x: %f, y: %f, z: %f\n", position.x, position.y, position.z);
  }

  if (position.y < 0.0) {
    position.y = 0.0;
  }
}

void Player::rotateMotion(int motionX, int motionY) {
  yaw += motionX * sensitivityX;
  pitch -= motionY * sensitivityY;
  if (pitch > 65.0f) {
    pitch = 65.0f;
  }
  if (pitch < -65.0f) {
    pitch = -65.0f;
  }
  glm::vec3 direction;
  direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  direction.y = sin(glm::radians(pitch));
  direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  dir = glm::normalize(direction);
  right = glm::normalize(glm::cross(dir, up));
}

void Player::camera(void) {
  glm::vec3 cameraPos;
  cameraPos.x = position.x - (dir.x * camera_distance);
  cameraPos.y = position.y - (dir.y * camera_distance) + 4.0;
  cameraPos.z = position.z - (dir.z * camera_distance);

  gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2],   // Posição da câmera
            position[0], position.y + 2.0, position[2], // Ponto de interesse
            up[0], up[1], up[2]                         // Vetor UP
  );
}
