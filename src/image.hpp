#pragma once

#include <iostream>

#include "geometry.hpp"

class Image {
  public:
    using Color = Vec3<u_char>;

    Image(size_t _width, size_t _height, const Color& _color)
      : width{_width}, height{_height}, color{_color} {}

    friend std::ostream& operator<<(std::ostream& o, const Image& image);

    const size_t width;
    const size_t height;
    const Color color;
};