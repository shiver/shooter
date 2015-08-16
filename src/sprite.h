#pragma once

#include <GL/glew.h>

#include "vector.h"

class Sprite {
public:
  Sprite();
  Sprite(Vector2<GLfloat>, Vector2<GLfloat>);

private:
  Vector2<GLfloat> dimensions;
  Vector2<GLfloat> position;
};
