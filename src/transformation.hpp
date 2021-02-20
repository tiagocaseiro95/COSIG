#pragma once

#include <memory>
#include <vector>

#include "geometry.hpp"

class Transformation {
  public:
    using Shared = std::shared_ptr<Transformation>;
    static Shared Build(const std::vector<Matrix44f>& matrixes) {
        return std::make_shared<Transformation>(matrixes);
    }
    Transformation(const std::vector<Matrix44f>& _matrixes);

  private:
    Matrix44f matrix_;
};

Matrix44f Scale(float x = 1.f, float y = 1.f, float z = 1.f);
Matrix44f Rotation(float x = 0.f, float y = 0.f, float z = 0.f);
Matrix44f Translation(float x = 0.f, float y = 0.f, float z = 0.f);