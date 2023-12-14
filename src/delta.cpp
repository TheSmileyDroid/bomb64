/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#include "../include/delta.h"

Uint64 NOW = 0;
Uint64 LAST = 0;
double deltaTime = 0;

void deltaInit(void) {
  NOW = SDL_GetPerformanceCounter();
  LAST = 0;
  deltaTime = 0;
}

void deltaUpdate(void) {
  LAST = NOW;
  NOW = SDL_GetPerformanceCounter();

  deltaTime =
      (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
}
