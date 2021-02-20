#include "material.hpp"

std::ostream& operator<<(std::ostream& o, const Material& material) {
    o << "color: " << material.color_ << std::endl;
    o << "ambient_cof: " << material.ambient_cof_ << std::endl;
    o << "diffuse_cof: " << material.diffuse_cof_ << std::endl;
    o << "reflection_cof: " << material.reflection_cof_ << std::endl;
    o << "refraction_cof: " << material.refraction_cof_ << std::endl;
    o << "refraction_index: " << material.refraction_index_ << std::endl;
    return o;
}
