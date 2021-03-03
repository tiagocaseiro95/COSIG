#pragma once

#include "color.hpp"
#include "geometry.hpp"

#include <memory>

class Material {
  public:
    using Shared = std::shared_ptr<Material>;

    static Shared Build(
        const Color& _color,
        float _ambient_cof,
        float _diffuse_cof,
        float _reflection_cof,
        float _refraction_cof,
        float _refraction_index) {
        return std::make_shared<Material>(
            _color, _ambient_cof, _diffuse_cof, _reflection_cof, _refraction_cof, _refraction_index);
    }
    Material(
        const Color& _color,
        float _ambient_cof,
        float _diffuse_cof,
        float _reflection_cof,
        float _refraction_cof,
        float _refraction_index)
      : color(_color), ambient_cof(_ambient_cof), diffuse_cof(_diffuse_cof),
        reflection_cof(_reflection_cof), refraction_cof(_refraction_cof),
        refraction_index(_refraction_index) {}


    friend std::ostream& operator<<(std::ostream& o, const Material& material);

    const Color color;
    const float ambient_cof;
    const float diffuse_cof;
    const float reflection_cof;
    const float refraction_cof;
    const float refraction_index;
};