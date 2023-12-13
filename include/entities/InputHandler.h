#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "IPlayer.h"
#include <SDL2/SDL_events.h>

class InputHandler {
public:
  void handleInput(IPlayer &player, SDL_Event *event);
  bool moveForward() const;
  bool moveBack() const;
  bool moveLeft() const;
  bool moveRight() const;
  bool performJump();

private:
  bool move_forward = false;
  bool move_back = false;
  bool move_left = false;
  bool move_right = false;
  bool do_jump = false;
};

#endif