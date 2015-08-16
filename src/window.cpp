#include <iostream>
#include <memory>
#include <utility>

#include <SDL.h>

#include "window.h"

Window::Window() {
  createWindow();
  createRenderer();
  createGLContext();
}

void Window::createWindow() {
  auto window = std::unique_ptr<SDL_Window, SDLDestroyer>(SDL_CreateWindow(
      "Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
      480, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE));

  if (window == nullptr) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
  } else {
    this->window = std::move(window);
  }
}

void Window::createRenderer() {
  auto renderer = std::unique_ptr<SDL_Renderer, SDLDestroyer>(
      SDL_CreateRenderer(this->window.get(), -1,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

  if (renderer == nullptr) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
  } else {
    this->renderer = std::move(renderer);
  }
}

void Window::createGLContext() {
  auto context = SDL_GL_CreateContext(this->window.get());

  if (context == nullptr) {
    std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
  } else {
    this->gl_context = std::unique_ptr<SDL_GLContext, SDLDestroyer>(&context);
  }
}

Window::Window(int w_opts, int r_opts)
    : window_opts(w_opts), renderer_opts(r_opts) {
  createWindow();
  createRenderer();
}

void Window::swapBuffers() { SDL_GL_SwapWindow(this->window.get()); }

Window::~Window() { SDL_Quit(); }
