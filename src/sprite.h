#pragma once

#include <memory>
#include <vector>

#include <GL/glew.h>

#include "vector.h"

class Sprite {
public:
  Sprite();
  Sprite(Vector2<>, Vector2<>);

  void assignMesh(const std::shared_ptr<std::vector<Vector3<>>>);

private:
  Vector2<> position;
  Vector2<> dimensions;

  GLuint vbo;
  std::shared_ptr<std::vector<Vector3<>>> mesh;
};

// vim: ts=2:sw=2:et:
