#include "render.h"

#include <GL/glew.h>
#include <easylogging++.h>

void Renderer::render() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}

// vim: ts=2:sw=2:et:
