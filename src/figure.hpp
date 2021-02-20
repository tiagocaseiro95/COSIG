#pragma once

#include <memory>

#include "material.hpp"
#include "ray.hpp"
#include "transformation.hpp"

class Figure {
  public:
    using Unique = std::unique_ptr<Figure>;
    Figure(const Transformation::Shared _transformation, const Material::Shared _material)
      : transformation_{_transformation}, material_{_material} {}
    virtual ~Figure()                             = default;
    virtual bool intersects(const Ray& ray) const = 0;
    virtual void print(std::ostream& o) const     = 0;
    friend std::ostream& operator<<(std::ostream& o, const Figure& figure);

  private:
    const Transformation::Shared transformation_;
    const Material::Shared material_;
};

class Sphere : public Figure {
  public:
    using Unique = std::unique_ptr<Sphere>;
    static Unique
    Build(const Transformation::Shared _transformation, const Material::Shared _material) {
        return std::make_unique<Sphere>(_transformation, _material);
    }
    Sphere(const Transformation::Shared _transformation, const Material::Shared _material)
      : Figure(_transformation, _material) {}
    ~Sphere() = default;
    void print(std::ostream& o) const override;
    bool intersects(const Ray& ray) const override { return true; }
};

class Box : public Figure {
  public:
    using Unique = std::unique_ptr<Box>;
    static Unique
    Build(const Transformation::Shared _transformation, const Material::Shared _material) {
        return std::make_unique<Box>(_transformation, _material);
    }
    Box(const Transformation::Shared _transformation, const Material::Shared _material)
      : Figure(_transformation, _material) {}
    ~Box() = default;
    void print(std::ostream& o) const override;
    bool intersects(const Ray& ray) const override { return true; }
};

class Triangle : public Figure {
  public:
    using Vertex = Vec3f;
    using Unique = std::unique_ptr<Triangle>;
    static Unique Build(
        const Transformation::Shared _transformation,
        const Material::Shared _material,
        const Vertex& _v0,
        const Vertex& _v1,
        const Vertex& _v2) {
        return std::make_unique<Triangle>(_transformation, _material, _v0, _v1, _v2);
    }
    Triangle(
        const Transformation::Shared _transformation,
        const Material::Shared _material,
        const Vertex& _v0,
        const Vertex& _v1,
        const Vertex& _v2)
      : Figure(_transformation, _material), v0_{_v0}, v1_{_v1}, v2_{_v2} {}
    ~Triangle() = default;
    void print(std::ostream& o) const override;
    bool intersects(const Ray& ray) const override { return true; }

  private:
    Vertex v0_;
    Vertex v1_;
    Vertex v2_;
};