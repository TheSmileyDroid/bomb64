/**
 * Nome: Gabriel Henrique Silva RA: 156514
 */
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_version.h>
#include <SDL2/SDL_video.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
using namespace glm;

#include "../include/camera.h"
#include "../include/delta.h"
#include "../include/entities/player.h"
#include "../include/ground.h"
#include "../include/lighting.h"

#include <glm/glm.hpp>
#include <vector>

GLfloat light0_pos[] = {20.0f, 20.0f, 60.0f, 1.0f};
GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat black[] = {0.0f, 0.2f, 0.0f, 1.0f};

GLdouble cameraX = 0.0f;
GLdouble cameraY = 0.0f;
GLdouble cameraZ = 24.0f;

SDL_Window *gWindow = NULL;
SDL_GLContext gContext;

int windowWidth = 640;
int windowHeight = 480;

Player player;

void quit(int status) {
  SDL_Quit();
  exit(status);
}

bool initGL(void) {
  bool success = true;
  GLenum error = GL_NO_ERROR;

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // define a cor de fundo
  glEnable(GL_DEPTH_TEST);              // habilita o teste de profundidade
  glMatrixMode(GL_MODELVIEW);           // define que a matrix é a model view
  glLoadIdentity();                     // carrega a matrix de identidade
  gluLookAt(4.0, 2.0, 1.0,              // posição da câmera
            0.0, 0.0, 0.0,              // para onde a câmera aponta
            0.0, 1.0, 0.0);             // vetor view-up

  glMatrixMode(GL_PROJECTION); // define que a matrix é a de projeção
  glLoadIdentity();            // carrega a matrix de identidade
  gluPerspective(90.0, 1.0, 0.1, 1024.0); // define a projeção perspectiva
  glViewport(0, 0, windowWidth, windowHeight); // define o viewport

  error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("Error initializing OpenGL! %s\n", gluErrorString(error));
    success = false;
  }

  glClearColor(0.5f, 0.5f, 0.9f, 0.f);

  error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("Error initializing OpenGL! %s\n", gluErrorString(error));
    success = false;
  }

  return success;
}

bool init(void) {
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    success = false;
  } else {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);

    gWindow = SDL_CreateWindow(
        "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
      success = false;
    } else {
      gContext = SDL_GL_CreateContext(gWindow);
      if (gContext == NULL) {
        printf("OpenGL context could not be created! SDL Error: %s\n",
               SDL_GetError());
        success = false;
      } else {
        if (SDL_GL_SetSwapInterval(1) < 0) {
          printf("Warning: Unable to set VSync! SDL Error: %s\n",
                 SDL_GetError());
        }

        if (!initGL()) {
          printf("Unable to initialize OpenGL!\n");
          success = false;
        }
      }
    }
  }

  player = Player();
  player.load_model();

  return success;
}

void grab_mouse(void) {
  SDL_SetWindowGrab(gWindow, SDL_TRUE);
  SDL_SetRelativeMouseMode(SDL_TRUE);
}

static void process_events(void) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {

    switch (event.type) {
    case SDL_KEYDOWN:
      cameraMovementKeyDown(&event.key.keysym);
      break;
    case SDL_KEYUP:
      cameraMovementKeyUp(&event.key.keysym);
      break;
    case SDL_MOUSEMOTION:
      cameraRotation(event.motion.xrel, event.motion.yrel);
      break;
    case SDL_QUIT:
      quit(0);
      break;
    case SDL_MOUSEBUTTONDOWN:
      grab_mouse();
      break;
    }
  }
}

void displayFunc(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  camera();

  glPushMatrix();
  glTranslatef(0.0, -10.0, 0.0);
  ground();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.0, 0.0, -5.0);
  glRotatef(67.0, 0.0, 1.0, 0.0);
  player.draw();
  glPopMatrix();

  lighting();

  glFlush();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  init();

  while (true) {
    deltaUpdate();
    process_events();
    cameraUpdate();
    displayFunc();
    SDL_GL_SwapWindow(gWindow);
  }

  return 0;
}
