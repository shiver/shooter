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
  ~Window();

  void swapBuffers();

private:
  void createWindow();
  void createRenderer();
  void createGLContext();

  std::unique_ptr<SDL_Window, SDLDestroyer> window;
  std::unique_ptr<SDL_Renderer, SDLDestroyer> renderer;
  std::unique_ptr<SDL_GLContext, SDLDestroyer> gl_context;

  int window_opts;
  int renderer_opts;
};
