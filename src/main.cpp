#include <iostream>
#include <utility>
#include <memory>
#include <SDL.h>


class Window {
public:
   Window();
	Window(int, int);
   ~Window();

private:
   void createWindow();
   void createRenderer();

	std::unique_ptr<SDL_Window> window;
	std::unique_ptr<SDL_Renderer> renderer;


   int window_opts;
   int renderer_opts;
};

Window::Window() {
   createWindow();
   createRenderer();
}

void Window::createWindow() {
   auto window = std::make_unique<SDL_Window>(
       SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN),
	   [](SDL_Window *w){SDL_DestroyWindow(w);}
   );

   if (window == nullptr) {
       std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
   } else {
       this->window = std::move(window);
   }
}

void Window::createRenderer() {
	auto renderer = std::make_unique<SDL_Renderer>(
       SDL_CreateRenderer(
           this->window.get(), -1,
           SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
       ), [](SDL_Renderer *r){SDL_DestroyRenderer(r);}
   );

   if (renderer == nullptr) {
       std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
   } else {
       this->renderer = std::move(renderer);
   }
}

Window::Window(int w_opts, int r_opts) : window_opts(w_opts), renderer_opts(r_opts) {
   createWindow();
   createRenderer();
}

Window::~Window() {

   SDL_Quit();
}

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

    //Window window();

	return EXIT_SUCCESS;
}
