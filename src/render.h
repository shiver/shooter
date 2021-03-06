#pragma once

#include "timer.h"
#include "resource.h"

class Renderer {
public:
  Renderer() : _cap_frames(false) {}
  ~Renderer();
  void render(const std::uint64_t); // TODO: temporary
  void init(); // TODO: temporary

  Renderer(std::uint32_t max_fps) {
    _frame_rate_timer = Timer{};
    _frame_counter = 0;
    _ticks_per_frame = 1000 / max_fps;
    _cap_frames = true;
  }

private:
  Timer _frame_rate_timer;
  std::uint32_t _frame_counter;
  std::uint32_t _ticks_per_frame;
  bool _cap_frames;

  GLuint VAO, VBO, EBO, shaderProgram;
};

// vim: ts=2:sw=2:et:
