#pragma once

#include <iostream>

#include "geometry.hpp"

class Image {
  public:
    using Color = Vec3f;

    Image(int _weight, int _height, const Color& _color)
      : weight_{_weight}, height_{_height}, color_{_color} {}

    friend std::ostream& operator<<(std::ostream& o, const Image& image);

  private:
    int weight_;
    int height_;
    Color color_;
};