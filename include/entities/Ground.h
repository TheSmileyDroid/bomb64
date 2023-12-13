#ifndef GROUND_H
#define GROUND_H

#include "Entity.h"

class Ground : public Entity {
public:
  Ground();
  void draw();
  void update();
};

#endif