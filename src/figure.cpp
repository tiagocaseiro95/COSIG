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
    o << "v0_: " << v0_ << std::endl;
    o << "v1_: " << v1_ << std::endl;
    o << "v2_: " << v2_ << std::endl;
}