#include "../include/delta.h"
#include <stdio.h>

int delta = 0;

void deltaInit(void) { delta = 0; }

void deltaUpdate(void) {
  static int last = 0;
  int now = SDL_GetTicks();
  delta = now - last;
  last = now;
}
