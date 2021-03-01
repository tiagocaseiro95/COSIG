#pragma once

#include <iostream>

#include "geometry.hpp"

class Image {
  public:
    using Color = Vec3<u_char>;

    Image(int _width, int _height, const Color& _color)
      : width_{_width}, height_{_height}, color_{_color} {}

    auto getWidth() const { return width_; }

    auto getHeight() const { return height_; }

    auto getColor() const { return color_; }

    friend std::ostream& operator<<(std::ostream& o, const Image& image);

  private:
    int width_;
    int height_;
    Color color_;
};