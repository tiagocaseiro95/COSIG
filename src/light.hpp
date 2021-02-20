#pragma once

#include "geometry.hpp"
#include "transformation.hpp"

class Light {
  public:
    using Color = Vec3f;

    Light(const Transformation::Shared& _transformation, const Color& _color)
      : transformation_(_transformation), color_(_color) {}

  private:
    const Transformation::Shared transformation_;
    const Color color_;
};