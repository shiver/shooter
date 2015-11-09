#pragma once

#include <memory>
#include <utility>

#include <SDL.h>

struct SDLDestroyer {
  void operator()(SDL_Window *w) const { SDL_DestroyWindow(w); }
  void operator()(SDL_Renderer *r) const { SDL_DestroyRenderer(r); }
  void operator()(SDL_GLContext *g) const { SDL_GL_DeleteContext(g); }
};

class Window {
public:
  Window();
  Window(int, int);

  Window(Window&& window) = default;
  ~Window();

  void swap_buffers();

private:
  void create_window();
  void create_renderer();
  void create_GLContext();
  bool initialise_image_support();

  std::unique_ptr<SDL_Window, SDLDestroyer> _window;
  std::unique_ptr<SDL_Renderer, SDLDestroyer> _renderer;
  std::unique_ptr<SDL_GLContext, SDLDestroyer> _gl_context;

  int _window_opts;
  int _renderer_opts;
};

// vim: ts=2:sw=2:et:
