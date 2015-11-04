#include <iostream>
#include <vector>
#include <utility>
#include <memory>

#include <GL/glew.h>
#include <easylogging++.h>

#include "game.h"
#include "resource.h"
#include "window.h"
#include "sprite.h"
#include "vector.h"
#include "util.h"
#include "timer.h"

Game::Game(std::unique_ptr<Window> window, std::unique_ptr<ResourceManager> resources) :
    _window(std::move(window)), _resources(std::move(resources)) {}

void Game::run() {
  std::uint32_t frames_rendered = 0;
  Timer rate_timer{};

  SDL_Event event;


  while (true) {
    rate_timer.start();

    if (frames_rendered <= 60) {
      glClearColor(0.0, 0.0, 0.0, 1.0);
      glClear(GL_COLOR_BUFFER_BIT);

      _window->swapBuffers();
      frames_rendered++;

      if (rate_timer.get_ticks() < 1000/60) {
        SDL_Delay(1000/60 - rate_timer.get_ticks());
      }
    } else {
      LOG(DEBUG) << "Frames capped: " << frames_rendered << " [" << rate_timer.get_ticks() << "]\n";

      rate_timer.stop();
      rate_timer.reset();
      frames_rendered = 0;
    }

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        LOG(INFO) << "Event: KEYDOWN";
        quit();
        break;
      case SDL_QUIT:
        goto break_game_loop;
        break;
      default:
        LOG(INFO) << "Event: UNKNOWN";
        break;
      }
    }
  }

break_game_loop:
  LOG(INFO) << "Game loop ended";
}

void Game::quit() {
  SDL_Event event;
  event.type = SDL_QUIT;
  SDL_PushEvent(&event);
}

// vim: ts=2:sw=2:et:
