#pragma once

#include <cmath>
#include <numbers>

#include "builder.hpp"
#include "geometry.hpp"

using Color = Vec3<u_char>;

class Material : public Builder<Material> {
  public:
    Material(
        const Color& _color,
        float _ambient_cof,
        float _diffuse_cof,
        float _reflection_cof,
        float _refraction_cof,
        float _refraction_index)
      : color(_color), ambient_cof(_ambient_cof), diffuse_cof(_diffuse_cof),
        reflection_cof(_reflection_cof), refraction_cof(_refraction_cof),
        refraction_index(_refraction_index) {}

    friend std::ostream& operator<<(std::ostream& o, const Material& material);

    const Color color;
    const float ambient_cof;
    const float diffuse_cof;
    const float reflection_cof;
    const float refraction_cof;
    const float refraction_index;
};

class Transformation
  : public Matrix44f
  , public Builder<Transformation> {
  public:
    Transformation(const Matrix44f& matrix = Matrix44f()) : Matrix44f(matrix) {}
    static Matrix44f Scale(float x, float y, float z);
    static Matrix44f RotationX(float angle);
    static Matrix44f RotationY(float angle);
    static Matrix44f RotationZ(float angle);
    static Matrix44f Translation(float x, float y, float z);
};
