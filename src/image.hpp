#pragma once

#include <iostream>

#include "geometry.hpp"

class Image {
  public:
    using Color = Vec3f;

    Image(int _width, int _height, const Color& _color)
      : width_{_width}, height_{_height}, color_{_color} {}

    int getWidth() const { return width_; }

    int getHeight() const { return height_; }

    Color getColor() const { return color_; }

    friend std::ostream& operator<<(std::ostream& o, const Image& image);

  private:
    int width_;
    int height_;
    Color color_;
};