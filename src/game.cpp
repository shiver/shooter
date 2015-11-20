#include <iostream>
#include <vector>
#include <utility>
#include <memory>

#include <easylogging++.h>
#include <GL/glew.h>

#include "game.h"
#include "resource.h"
#include "shader.h"
#include "window.h"
#include "sprite.h"
#include "vector.h"
#include "util.h"
#include "timer.h"
#include "render.h"
#include "SDL_image.h"

const std::uint32_t MAX_FPS = 60;
const std::uint32_t TICKS_PER_FRAME = 1000/MAX_FPS;

Game::Game(std::unique_ptr<Window> window, std::shared_ptr<ResourceManager> resources) :
    _window(std::move(window)), _resources(std::move(resources)) {}

void Game::run() {
  std::uint32_t frames_rendered = 0;
  Timer rate_timer{};
  Renderer renderer{MAX_FPS};

  // TODO: SceneManager to provide components such as Resources
  // to relevant parts in the pipeline, such as the renderer.
  auto vert = _resources->create<ShaderResource>(
      "../src/shaders/triangle.vert",
      GL_VERTEX_SHADER
  );

  auto frag = _resources->create<ShaderResource>(
      "../src/shaders/triangle.frag",
      GL_FRAGMENT_SHADER
  );

  // TODO: Combine shaders into program
  auto program = _resources->create<ShaderProgram>(
      ResourceList{_resources->get(vert), _resources->get(frag)}
  );

  // TODO: Move VAOs to own class
  renderer.init();
  auto program_id = std::static_pointer_cast<ShaderProgram>(_resources->get(program))->get();

  LOG(DEBUG) << "Program ID: " << program_id;

  rate_timer.start();
  while (true) {

    if (frames_rendered < MAX_FPS) {
      renderer.render(program_id);
      _window->swap_buffers();
      frames_rendered++;
    } else {

      if (rate_timer.get_ticks() < TICKS_PER_FRAME) {
      //  LOG(DEBUG) << "Frames capped: " << frames_rendered << " [" << rate_timer.get_ticks() << "]\n";
        float delay = TICKS_PER_FRAME - rate_timer.get_ticks();
      //  LOG(DEBUG) << "Waiting for: " << delay << "\n";
        SDL_Delay(delay);
      }

      rate_timer.stop();
      rate_timer.reset();
      frames_rendered = 0;
    }


    SDL_Event event;
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
