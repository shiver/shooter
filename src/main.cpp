#include <iostream>

#include <SDL.h>

#include "game.h"
#include "window.h"

int main(int argc, char **args) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  Window window{};
  Game game{window};
  game.run();

  return EXIT_SUCCESS;
}
