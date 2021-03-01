#include "ray.hpp"

std::ostream& operator<<(std::ostream& out, const Ray& ray) {
    out << "Origin   :" << ray.origin << std::endl;
    out << "Direction:" << ray.direction << std::endl;
    return out;
}
