/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#ifndef LIGHTING_H
#define LIGHTING_H

#include <GL/glut.h>
#include <math.h>

extern GLfloat light0_pos[4];
extern GLfloat white[4];
extern GLfloat black[4];

/**
 * @brief Essa função é responsável por criar a iluminação do jogo.
 * @return void
 */
void lighting();

#endif
