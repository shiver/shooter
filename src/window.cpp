#include <iostream>
#include <memory>
#include <utility>

#include <easylogging++.h>
#include <GL/glew.h>
#include <SDL_image.h>

#include "window.h"

Window::Window() {
  create_window();
  create_renderer();
  create_GLContext();
  initialise_image_support();
}

bool Window::initialise_image_support() {
  int img_flags = IMG_Init(IMG_INIT_PNG);
  if ((img_flags & IMG_INIT_PNG) != IMG_INIT_PNG) {
      LOG(ERROR) << "SDL2_image failed to initialise PNG support: " << IMG_GetError() << "\n";
      return false;
  }

  return true;
}

void Window::create_window() {
  auto window = std::unique_ptr<SDL_Window, SDLDestroyer>(SDL_CreateWindow(
      "Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
      480, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE));

  if (window == nullptr) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
  } else {
    _window = std::move(window);
  }
}

void Window::create_renderer() {
  auto renderer = std::unique_ptr<SDL_Renderer, SDLDestroyer>(
      SDL_CreateRenderer(_window.get(), -1,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

  if (renderer == nullptr) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
  } else {
    _renderer = std::move(renderer);
  }
}

void Window::create_GLContext() {
  auto context = SDL_GL_CreateContext(_window.get());

  if (context == nullptr) {
    std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
  } else {
    _gl_context = std::unique_ptr<SDL_GLContext, SDLDestroyer>(&context);
  }
}

Window::Window(int w_opts, int r_opts)
    : _window_opts(w_opts), _renderer_opts(r_opts) {
  create_window();
  create_renderer();
  initialise_image_support();

  glViewport(0, 0, 640, 480);
}

void Window::swap_buffers() { SDL_GL_SwapWindow(_window.get()); }

Window::~Window() { SDL_Quit(); }

// vim: ts=2:sw=2:et:
