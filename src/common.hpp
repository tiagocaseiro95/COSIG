#pragma once

#include "geometry.hpp"

class Color : public Vec3<u_char> {
  public:
    Color(u_char x, u_char y, u_char z) : Vec3<u_char>(x, y, z) {}
};