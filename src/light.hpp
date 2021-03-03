#pragma once

#include "geometry.hpp"
#include "transformation.hpp"

class Light {
  public:
    using Color = Vec3f;

    Light(const Transformation::Shared& _world, const Color& _color)
      : world(_world), color(_color) {}

    const Transformation::Shared world;
    const Color color;
};