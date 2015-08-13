#include <iostream>
#include <utility>
#include <memory>
#include <SDL.h>
#include <GL/glew.h>

struct SDLDestroyer {
  void operator()(SDL_Window *w) const { SDL_DestroyWindow(w); }
  void operator()(SDL_Renderer *r) const { SDL_DestroyRenderer(r); }
};

class Window {
public:
  Window();
  Window(int, int);
  ~Window();

private:
  void createWindow();
  void createRenderer();

  std::unique_ptr<SDL_Window, SDLDestroyer> window;
  std::unique_ptr<SDL_Renderer, SDLDestroyer> renderer;

  int window_opts;
  int renderer_opts;
};

Window::Window() {
  createWindow();
  createRenderer();
}

void Window::createWindow() {
  auto window = std::unique_ptr<SDL_Window, SDLDestroyer>(SDL_CreateWindow(
      "Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
      480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN));

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

Window::Window(int w_opts, int r_opts)
    : window_opts(w_opts), renderer_opts(r_opts) {
  createWindow();
  createRenderer();
}

Window::~Window() { SDL_Quit(); }

class Game {
public:
  Game();
  Game(const Window &);
  void run();
  void quit();

private:
  const Window &window;
};

Game::Game(const Window &window) : window(window) {}

void Game::run() {
  SDL_Event event;

  while (true) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        std::cout << "KEYDOWN\n";
        this->quit();
        break;
      case SDL_QUIT:
        goto break_game_loop;
        break;
      default:
        std::cout << "Unhandled\n";
        break;
      }
    }
  }

break_game_loop:
  std::cout << "Game over!\n";
}

void Game::quit() {
  SDL_Event event;
  event.type = SDL_QUIT;
  SDL_PushEvent(&event);
}

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
