#pragma once

#include <memory>
#include <vector>

#include "geometry.hpp"

class Transformation {
  public:
    using Shared = std::shared_ptr<Transformation>;
    static Shared Build(const std::vector<Matrix44f>& matrices) {
        return std::make_shared<Transformation>(matrices);
    }
    explicit Transformation(const std::vector<Matrix44f>& _matrices);

    template <typename T>
    void transformPoint(Vec3<T>& point) {
        matrix_.multVecMatrix(point, point);
    }

    template <typename T>
    void transformDirection(Vec3<T>& direction) {
        matrix_.multVecMatrix(direction, direction);
    }

  private:
    const Matrix44f matrix_;
};

Matrix44f Scale(float x = 1.f, float y = 1.f, float z = 1.f);
Matrix44f RotationX(float angle = 0);
Matrix44f RotationY(float angle = 0);
Matrix44f RotationZ(float angle = 0);
Matrix44f Translation(float x = 0.f, float y = 0.f, float z = 0.f);