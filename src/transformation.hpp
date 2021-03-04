#pragma once

#include <memory>
#include <vector>

#include "builder.hpp"
#include "geometry.hpp"

class Transformation
  : public Matrix44f
  , public Builder<Transformation> {
  public:
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