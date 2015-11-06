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
#include "render.h"
#include "SDL_image.h"

const int MAX_FPS = 60;
const int TICKS_PER_FRAME = 1000/MAX_FPS;

Game::Game(std::unique_ptr<Window> window, std::unique_ptr<ResourceManager> resources) :
    _window(std::move(window)), _resources(std::move(resources)) {}

void check_img() {
	SDL_version compile_version;
	SDL_IMAGE_VERSION(&compile_version);
	LOG(DEBUG) << "compiled with SDL_image version: " <<
					compile_version.major << "." <<
					compile_version.minor << "." <<
					compile_version.patch << "\n";
	LOG(DEBUG) << "running with SDL_image version: " <<
					link_version->major << "." <<
					link_version->minor << "." <<
					link_version->patch << "\n";
}

void Game::run() {
  std::uint32_t frames_rendered = 0;
  Timer rate_timer{};
  Renderer renderer{MAX_FPS};
  SDL_Event event;

	check_img();
	int img = IMG_Init(IMG_INIT_PNG);
	LOG(DEBUG) << "img: " << img << "\n";

  rate_timer.start();
  while (true) {

    if (frames_rendered < MAX_FPS) {
      renderer.render();
      _window->swapBuffers();
      frames_rendered++;
    } else {

      if (rate_timer.get_ticks() < TICKS_PER_FRAME) {
        LOG(DEBUG) << "Frames capped: " << frames_rendered << " [" << rate_timer.get_ticks() << "]\n";
        float delay = TICKS_PER_FRAME - rate_timer.get_ticks();
        LOG(DEBUG) << "Waiting for: " << delay << "\n";
        SDL_Delay(delay);
      }

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
