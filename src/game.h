#pragma once

#include "window.h"
#include "resource.h"

class Game {
public:
  Game();
  Game(Window&&);
  Game(std::unique_ptr<Window>, std::shared_ptr<ResourceManager>);

  void run();
  void quit();

private:
  std::unique_ptr<Window> _window;
  std::shared_ptr<ResourceManager> _resources;
};

// vim: ts=2:sw=2:et:
