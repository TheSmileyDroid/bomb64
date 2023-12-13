#ifndef IPLAYER_H
#define IPLAYER_H

#include <SDL2/SDL_events.h>

class IPlayer {
public:
  virtual void rotateMotion(int motionX, int motionY) = 0;
};

#endif