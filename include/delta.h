#ifndef DELTA_H
#define DELTA_H

#include <SDL2/SDL.h>
#include <cstdio>
#include <glm/common.hpp>
#include <stdio.h>

extern double deltaTime;

void deltaInit();

void deltaUpdate();

#endif