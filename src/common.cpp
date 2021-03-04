
#include "common.hpp"

static constexpr float ToRadians(const float degrees) {
    return degrees * std::numbers::pi_v<float> / 180.f;
}

std::ostream& operator<<(std::ostream& o, const Material& material) {
    o << "color: " << material.color << std::endl;
    o << "ambient_cof: " << material.ambient_cof << std::endl;
    o << "diffuse_cof: " << material.diffuse_cof << std::endl;
    o << "reflection_cof: " << material.reflection_cof << std::endl;
    o << "refraction_cof: " << material.refraction_cof << std::endl;
    o << "refraction_index: " << material.refraction_index << std::endl;
    return o;
}

Matrix44f Transformation::Scale(float x, float y, float z) {
    auto matrix  = Matrix44f();
    matrix[0][0] = x;
    matrix[1][1] = y;
    matrix[2][2] = z;
    return matrix;
}

Matrix44f Transformation::RotationX(float angle) {
    auto radians = ToRadians(angle);
    auto matrix  = Matrix44f();
    matrix[1][1] = std::cos(radians);
    matrix[2][1] = std::sin(radians);
    matrix[1][2] = -std::sin(radians);
    matrix[2][2] = std::cos(radians);
    return matrix;
}

Matrix44f Transformation::RotationY(float angle) {
    auto radians = ToRadians(angle);
    auto matrix  = Matrix44f();
    matrix[0][0] = std::cos(radians);
    matrix[0][2] = std::sin(radians);
    matrix[2][0] = -std::sin(radians);
    matrix[2][2] = std::cos(radians);
    return matrix;
}

Matrix44f Transformation::RotationZ(float angle) {
    auto radians = ToRadians(angle);
    auto matrix  = Matrix44f();
    matrix[0][0] = std::cos(radians);
    matrix[1][0] = std::sin(radians);
    matrix[0][1] = -std::sin(radians);
    matrix[1][1] = std::cos(radians);
    return matrix;
}

Matrix44f Transformation::Translation(float x, float y, float z) {
    auto matrix  = Matrix44f();
    matrix[0][3] = x;
    matrix[1][3] = y;
    matrix[2][3] = z;

    return matrix;
}