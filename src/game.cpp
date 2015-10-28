#include <iostream>
#include <vector>
#include <utility>
#include <memory>

#include <GL/glew.h>

#include "game.h"
#include "resource.h"
#include "window.h"
#include "sprite.h"
#include "vector.h"
#include "util.h"

Game::Game(std::unique_ptr<Window> window, std::unique_ptr<ResourceManager> resources) : 
    _window(std::move(window)), _resources(std::move(resources)) {}

void Game::run() {
  SDL_Event event;

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  _window->swapBuffers();

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
