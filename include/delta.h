/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#ifndef DELTA_H
#define DELTA_H

#include <SDL2/SDL.h>
#include <cstdio>
#include <glm/common.hpp>
#include <stdio.h>

extern double deltaTime;

/**
 * @brief Initializes the delta module.
 *
 * This function initializes the delta module and prepares it for use.
 * It should be called before any other functions from the delta module are
 * used.
 */
void deltaInit();

/**
 * @brief Atualiza o valor do delta.
 *
 * Essa função é responsável por atualizar o valor do delta, que é utilizado
 * para calcular a diferença entre dois pontos no tempo.
 */
void deltaUpdate();

#endif