#include <iostream>

#include <GL/glew.h>

#include "game.h"

Game::Game(Window &window) : window(window) {}

void Game::run() {
  SDL_Event event;

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  window.swapBuffers();

  while (true) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        std::cout << "KEYDOWN\n";
        this->quit();
        break;
      case SDL_QUIT:
        goto break_game_loop;
        break;
      default:
        std::cout << "Unhandled\n";
        break;
      }
    }
  }

break_game_loop:
  std::cout << "Game over!\n";
}

void Game::quit() {
  SDL_Event event;
  event.type = SDL_QUIT;
  SDL_PushEvent(&event);
}
