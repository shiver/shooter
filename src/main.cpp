#include <iostream>

#include <SDL.h>

#include "game.h"
#include "window.h"
#include "resource.h"
#include "util.h"

int main(int argc, char **args) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  auto main_window = make_unique<Window>();
  auto resource_manager = make_unique<ResourceManager>();

  auto game = Game(std::move(main_window), std::move(resource_manager));
  game.run();

  return EXIT_SUCCESS;
}
