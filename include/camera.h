/*
 * Author: Gabriel Henrique Silva
 * RA: 156514
 * Email: gabriel.henrique07@unifesp.br
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>
#include <SDL2/SDL_keyboard.h>

#include <math.h>
#include <stdbool.h>

extern GLfloat camera_pos[3];
extern GLfloat camera_center[3];
extern GLfloat camera_up[3];

/**
 * @brief Setup the camera.
 *
 * This function is responsible for setting up the camera and placing it in the
 * scene.
 */
void camera();

/**
 * @brief Handles key release events for camera movement.
 *
 * This function is responsible for handling key release events for camera
 * movement. It takes an SDL_Keysym pointer as a parameter.
 *
 * @param key The SDL_Keysym pointer representing the key release event.
 */
void cameraMovementKeyUp(SDL_Keysym *key);
/**
 * @brief Handles the keydown event for camera movement.
 *
 * This function is responsible for handling the keydown event for camera
 * movement. It takes an SDL_Keysym pointer as a parameter.
 *
 * @param key The SDL_Keysym pointer representing the key that was pressed.
 */
void cameraMovementKeyDown(SDL_Keysym *key);

/**
 * @brief Atualiza a câmera.
 *
 * Esta função é responsável por atualizar a posição e orientação da câmera.
 * Ela deve ser chamada a cada quadro para garantir que a câmera esteja sempre
 * sincronizada com a cena.
 */
void cameraUpdate();

/**
 * @brief Rotates the camera based on mouse motion.
 *
 * This function is responsible for rotating the camera based on mouse motion.
 */
void cameraRotation(int x, int y);

#endif