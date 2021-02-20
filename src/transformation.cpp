#include "transformation.hpp"

#include <numeric>

Transformation::Transformation(const std::vector<Matrix44f>& _matrixes) : matrix_{} {
    std::reduce(_matrixes.cbegin(), _matrixes.cend(), matrix_, std::multiplies{});
}

Matrix44f Scale(float x, float y, float z) {
    // std::cout << "Scale:" << x << ", " << y << ", " << z << std::endl;
    return Matrix44f();
}
Matrix44f Rotation(float x, float y, float z) {
    // std::cout << "Rotation:" << x << ", " << y << ", " << z << std::endl;
    return Matrix44f();
}
Matrix44f Translation(float x, float y, float z) {
    // std::cout << "Translation:" << x << ", " << y << ", " << z << std::endl;
    return Matrix44f();
}