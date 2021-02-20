#pragma once

#include "geometry.hpp"

#include <memory>

class Material {
  public:
    using Color  = Vec3f;
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
      : color_(_color), ambient_cof_(_ambient_cof), diffuse_cof_(_diffuse_cof),
        reflection_cof_(_reflection_cof), refraction_cof_(_refraction_cof),
        refraction_index_(_refraction_index) {}


    friend std::ostream& operator<<(std::ostream& o, const Material& material);


  private:
    const Color color_;
    const float ambient_cof_;
    const float diffuse_cof_;
    const float reflection_cof_;
    const float refraction_cof_;
    const float refraction_index_;
};