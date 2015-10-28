#pragma once

#include "window.h"
#include "resource.h"

class Game {
public:
  Game();
  Game(Window&&);
  Game(std::unique_ptr<Window>, std::unique_ptr<ResourceManager>);

  void run();
  void quit();

private:
  std::unique_ptr<Window> _window;
  std::unique_ptr<ResourceManager> _resources;
};
