#include "../../include/entities/InputHandler.h"

void InputHandler::handleInput(IPlayer &player, SDL_Event *event) {
  switch (event->type) {
  case SDL_KEYDOWN:
    switch (event->key.keysym.sym) {
    case SDLK_w:
      move_forward = true;
      break;
    case SDLK_s:
      move_back = true;
      break;
    case SDLK_a:
      move_left = true;
      break;
    case SDLK_d:
      move_right = true;
      break;
    case SDLK_SPACE:
      do_jump = true;
      break;
    default:
      break;
    }
    break;
  case SDL_KEYUP:
    switch (event->key.keysym.sym) {
    case SDLK_w:
      move_forward = false;
      break;
    case SDLK_s:
      move_back = false;
      break;
    case SDLK_a:
      move_left = false;
      break;
    case SDLK_d:
      move_right = false;
      break;
    default:
      break;
    }
    break;
  case SDL_MOUSEMOTION:
    player.rotateMotion(event->motion.xrel, event->motion.yrel);
    break;
  default:
    break;
  }
}

bool InputHandler::moveForward() const { return move_forward; }

bool InputHandler::moveBack() const { return move_back; }

bool InputHandler::moveLeft() const { return move_left; }

bool InputHandler::moveRight() const { return move_right; }

bool InputHandler::performJump() {
  bool jump = do_jump;
  do_jump = false;
  return jump;
}
