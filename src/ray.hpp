#pragma once

#include "geometry.hpp"
#include <iostream>

class Ray {
  public:
    Ray(const Vec3f& _origin, const Vec3f& _direction) : origin(_origin), direction(_direction) {}
    friend std::ostream& operator<<(std::ostream& out, const Ray& ray);
    const Vec3f origin;
    const Vec3f direction;
};