#pragma once

#include "common.hpp"
#include "geometry.hpp"
#include "transformation.hpp"

class Light {
  public:
    Light(const Transformation::Shared& _world, const Color& _color)
      : world(_world), color(_color) {}

    const Transformation::Shared world;
    const Color color;
};