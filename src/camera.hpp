#pragma once

#include "common.hpp"

class Camera {
  public:
    Camera(Transformation::Shared _world, float _distance, float _fov)
      : world{_world}, distance{_distance}, fov{_fov} {}

    const Transformation::Shared world;
    const float distance;
    const float fov;
};