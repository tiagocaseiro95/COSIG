#pragma once

#include "geometry.hpp"

class Ray {
  public:
    Ray(const Vec3f& _origin, const Vec3f& _direction) : origin_(_origin), direction_(_direction) {}

  private:
    const Vec3f origin_;
    const Vec3f direction_;
};