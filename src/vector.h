#pragma once

template <class T> class Vector2 {
public:
  Vector2(T x, T y) : x(x), y(y){};

private:
  T x;
  T y;
};
