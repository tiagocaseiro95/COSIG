#include "image.hpp"

std::ostream& operator<<(std::ostream& o, const Image& image) {
    std::cout << "width: " << image.width << std::endl;
    std::cout << "height: " << image.height << std::endl;
    std::cout << "color: " << image.color << std::endl;
    return o;
}