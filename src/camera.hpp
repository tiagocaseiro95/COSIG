#pragma once

#include <memory>

#include "transformation.hpp"

class Camera {
  public:
    Camera(Transformation::Shared _transformation, float _distance, float _fov)
      : transformation_{_transformation}, distance_{_distance}, fov_{_fov} {}

    auto getTransformation() const { return transformation_; }

    auto getDistance() const { return distance_; }

    auto getFov() const { return fov_; }

  private:
    Transformation::Shared transformation_;
    float distance_;
    float fov_;
};