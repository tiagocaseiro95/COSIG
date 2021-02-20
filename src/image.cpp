#include "image.hpp"

std::ostream& operator<<(std::ostream& o, const Image& image) {
    std::cout << "weight: " << image.weight_ << std::endl;
    std::cout << "height: " << image.height_ << std::endl;
    std::cout << "color: " << image.color_ << std::endl;
    return o;
}