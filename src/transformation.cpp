#include "transformation.hpp"

#include <cmath>
#include <numbers>
/**
 * @brief Converts from degrees to radians
 *
 * @param degrees
 * @return constexpr float
 */
static constexpr float ToRadians(const float degrees) {
    return degrees * std::numbers::pi_v<float> / 180.f;
}

Matrix44f Scale(float x, float y, float z) {
    auto matrix  = Matrix44f();
    matrix[0][0] = x;
    matrix[1][1] = y;
    matrix[2][2] = z;
    return matrix;
}

Matrix44f RotationX(float angle) {
    auto radians = ToRadians(angle);
    auto matrix  = Matrix44f();
    matrix[1][1] = std::cos(radians);
    matrix[2][1] = std::sin(radians);
    matrix[1][2] = -std::sin(radians);
    matrix[2][2] = std::cos(radians);
    return matrix;
}

Matrix44f RotationY(float angle) {
    auto radians = ToRadians(angle);
    auto matrix  = Matrix44f();
    matrix[0][0] = std::cos(radians);
    matrix[0][2] = std::sin(radians);
    matrix[2][0] = -std::sin(radians);
    matrix[2][2] = std::cos(radians);
    return matrix;
}

Matrix44f RotationZ(float angle) {
    auto radians = ToRadians(angle);
    auto matrix  = Matrix44f();
    matrix[0][0] = std::cos(radians);
    matrix[1][0] = std::sin(radians);
    matrix[0][1] = -std::sin(radians);
    matrix[1][1] = std::cos(radians);
    return matrix;
}

Matrix44f Translation(float x, float y, float z) {
    auto matrix  = Matrix44f();
    matrix[0][3] = x;
    matrix[1][3] = y;
    matrix[2][3] = z;

    return matrix;
}