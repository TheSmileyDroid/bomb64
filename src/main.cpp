/**
 * Nome: Gabriel Henrique Silva RA: 156514
 */
#include <memory>
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
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace glm;

#include "../include/camera.h"
#include "../include/delta.h"
#include "../include/entities/Cadeira.h"
#include "../include/entities/Ground.h"
#include "../include/entities/Player.h"
#include "../include/lighting.h"

SDL_Window *gWindow = NULL;
SDL_GLContext gContext;

int windowWidth = 640;
int windowHeight = 480;

Player *player;
std::vector<Entity *> entities;

void quit(int status) {
  SDL_Quit();
  exit(status);
}

bool initGL(void) {
  bool success = true;
  GLenum error = GL_NO_ERROR;

  glClearColor(0.5f, 0.5f, 0.9f, 0.f);
  glEnable(GL_DEPTH_TEST); // habilita o teste de profundidade
  glDepthFunc(GL_LEQUAL);  // tipo de teste de profundidade a ser feito
  glShadeModel(GL_SMOOTH); // tipo de "suavização"
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // correcao de perspectiva
  glEnable(GL_TEXTURE_2D);                           // habilita texturas
  glMatrixMode(GL_MODELVIEW); // define que a matrix é a model view
  glLoadIdentity();           // carrega a matrix de identidade

  glMatrixMode(GL_PROJECTION); // define que a matrix é a de projeção
  glLoadIdentity();            // carrega a matrix de identidade
  gluPerspective(90.0, (GLfloat)windowWidth / (GLfloat)windowHeight, 1.0,
                 1024.0); // define a projeção perspectiva
  glViewport(0, 0, windowWidth, windowHeight); // define o viewport

  error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("Error initializing OpenGL! %s\n", gluErrorString(error));
    success = false;
  }

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
        "Bomb 64", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
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

  player = new Player();

  entities.push_back(new Ground());
  entities.push_back(player);
  entities.push_back(new Cadeira());

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
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        SDL_SetWindowGrab(gWindow, SDL_FALSE);
        SDL_SetRelativeMouseMode(SDL_FALSE);
        break;
      }
      break;
    case SDL_QUIT:
      quit(0);
      break;
    case SDL_MOUSEBUTTONDOWN:
      grab_mouse();
      break;
    }

    player->input(&event);
  }
}

void drawScene(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  player->camera();

  for (auto entity : entities) {
    entity->draw();
  }

  // Draw AABB for debugging
  for (auto entity : entities) {
    glPushMatrix();
    glTranslatef(entity->position.x, entity->position.y, entity->position.z);
    glScalef(entity->aabb->max.x - entity->aabb->min.x,
             entity->aabb->max.y - entity->aabb->min.y,
             entity->aabb->max.z - entity->aabb->min.z);
    glutWireCube(1.0);
    glPopMatrix();
  }
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  init();
  deltaInit();

  glClearColor(0.5f, 0.5f, 0.9f, 0.f);

  Uint32 lastFrameTime = SDL_GetTicks();
  float delta = 0.0f;
  float fps = 0.0f;
  (void)fps;

  while (true) {
    Uint32 currentFrameTime = SDL_GetTicks();
    delta = (currentFrameTime - lastFrameTime) / 1000.0f;
    fps = 1.0f / delta;
    lastFrameTime = currentFrameTime;

    deltaUpdate();
    lighting();
    process_events();
    player->update();
    drawScene();

    SDL_GL_SwapWindow(gWindow);
  }

  return 0;
}
