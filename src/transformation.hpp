#pragma once

#include <memory>
#include <vector>

#include "geometry.hpp"

struct Transformation : Matrix44f {
    using Shared = std::shared_ptr<Transformation>;
    static Shared Build(const Matrix44f& matrix) {
        return std::make_shared<Transformation>(matrix);
    }
    Transformation(const Matrix44f& matrix) : Matrix44f(matrix) {}
};
/**
 * @brief Generates scale transformation matrix
 *
 * @param x
 * @param y
 * @param z
 * @return Matrix44f
 */
Matrix44f Scale(float x, float, float z);

/**
 * @brief Generates rotation matrix on x axis
 *
 * @param angle
 * @return Matrix44f
 */
Matrix44f RotationX(float angle);

/**
 * @brief Generates rotation matrix on y axis
 *
 * @param angle
 * @return Matrix44f
 */
Matrix44f RotationY(float angle);

/**
 * @brief Generates rotation matrix on z axis
 *
 * @param angle
 * @return Matrix44f
 */
Matrix44f RotationZ(float angle);

/**
 * @brief Generates translation matrix
 *
 * @param x
 * @param y
 * @param z
 * @return Matrix44f
 */
Matrix44f Translation(float x, float y, float z);