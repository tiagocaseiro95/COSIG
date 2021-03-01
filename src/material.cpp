#include "material.hpp"

std::ostream& operator<<(std::ostream& o, const Material& material) {
    o << "color: " << material.color << std::endl;
    o << "ambient_cof: " << material.ambient_cof << std::endl;
    o << "diffuse_cof: " << material.diffuse_cof << std::endl;
    o << "reflection_cof: " << material.reflection_cof << std::endl;
    o << "refraction_cof: " << material.refraction_cof << std::endl;
    o << "refraction_index: " << material.refraction_index << std::endl;
    return o;
}
