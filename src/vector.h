#pragma once

#include <GL/glew.h>

template <class T = GLfloat> class Vector2 {
public:
  Vector2(T x, T y) : x(x), y(y){};

private:
  T x;
  T y;
};

template <class T = GLfloat> class Vector3 {
public:
  Vector3(T x, T y, T z) : x(x), y(y), z(z){};

private:
  T x;
  T y;
  T z;
};

// vim: ts=2:sw=2:et:
