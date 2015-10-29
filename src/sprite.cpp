#include <utility>
#include <vector>

#include <GL/glew.h>

#include "vector.h"
#include "sprite.h"

Sprite::Sprite(Vector2<> position, Vector2<> dimensions)
    : position(position), dimensions(dimensions) {}

void Sprite::assignMesh(const std::shared_ptr<std::vector<Vector3<>>> mesh) {
  this->mesh = mesh;

  glGenBuffers(1, &this->vbo);
  glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(this->mesh.get()->data()),
               mesh.get()->data(), GL_STATIC_DRAW);
}

// vim: ts=2:sw=2:et:
