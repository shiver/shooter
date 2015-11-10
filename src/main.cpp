#include <iostream>

#include <SDL.h>

#include <easylogging++.h>
INITIALIZE_EASYLOGGINGPP

#include "game.h"
#include "window.h"
#include "resource.h"
#include "util.h"

int main(int argc, char* argv[]) {
  LOG(INFO) << "Startup";

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    LOG(ERROR) << "SDL_Init Error: " << SDL_GetError() << "\n";
    return EXIT_FAILURE;
  }

  auto main_window = make_unique<Window>();
  auto resource_manager = std::make_shared<ResourceManager>();

  auto game = Game(std::move(main_window), std::move(resource_manager));
  game.run();

  LOG(INFO) << "Shutdown";
  return EXIT_SUCCESS;
}

// vim: ts=2:sw=2:et:
