#include <iostream>
#include <vector>
#include <utility>

#include <GL/glew.h>

#include "game.h"
#include "sprite.h"
#include "vector.h"

Game::Game(Window &window) : window(window) {}

void Game::run() {
  SDL_Event event;

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  Sprite sprite{Vector2<>(0.0, 0.0), Vector2<>(0.0, 0.0)};
  std::vector<Vector3<>> mesh{
      {-0.5f, -0.5f, 0.0f}, {0.5f, -0.5f, 0.0f}, {0.0f, 0.5f, 0.0f}};

  auto shared = std::make_shared<std::vector<Vector3<>>>(mesh);
  sprite.assignMesh(shared);

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
