#include "figure.hpp"

std::ostream& operator<<(std::ostream& o, const Figure& figure) {
    figure.print(o);
    return o;
}

void Sphere::print(std::ostream& o) const {
    o << "Sphere" << std::endl;
}

void Box::print(std::ostream& o) const {
    o << "Box" << std::endl;
}

void Triangle::print(std::ostream& o) const {
    o << "v0: " << v0 << std::endl;
    o << "v1: " << v1 << std::endl;
    o << "v2: " << v2 << std::endl;
}