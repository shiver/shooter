#pragma once

#include "window.h"

class Game {
public:
  Game();
  Game(Window &);
  void run();
  void quit();

private:
  Window &window;
};
