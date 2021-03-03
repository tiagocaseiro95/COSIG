#pragma once

#include "geometry.hpp"

struct Color : Vec3<u_char> {
    Color(u_char x, u_char y, u_char z) : Vec3<u_char>(x, y, z) {}
};