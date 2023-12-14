#ifndef BRICK_H
#define BRICK_H

#include "Entity.h"

class Brick : public Entity {
public:
  Brick();
  Brick(glm::vec3 position);
};

#endif // BRICK_H