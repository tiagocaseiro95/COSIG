#pragma once

#include <memory>

#include "transformation.hpp"

class Camera {
  public:
    Camera(Transformation::Shared _world, float _distance, float _fov)
      : world_{_world}, distance_{_distance}, fov_{_fov} {}

    auto getWorld() const { return world_; }

    auto getDistance() const { return distance_; }

    auto getFov() const { return fov_; }

  private:
    Transformation::Shared world_;
    float distance_;
    float fov_;
};