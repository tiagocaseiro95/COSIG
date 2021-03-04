#pragma once

#include <memory>

#include "material.hpp"
#include "ray.hpp"
#include "transformation.hpp"

class Figure {
  public:
    using Unique = std::unique_ptr<Figure>;
    Figure(const Transformation::Shared& _world, const Material::Shared& _material)
      : world{_world}, material{_material} {}
    virtual ~Figure()                                           = default;
    virtual bool intersects(const Ray& ray, float& depth) const = 0;
    virtual void print(std::ostream& o) const                   = 0;
    friend std::ostream& operator<<(std::ostream& o, const Figure& figure);

    const Transformation::Shared world;
    const Material::Shared material;
};

class Sphere : public Figure {
  public:
    using Unique = std::unique_ptr<Sphere>;
    static Unique Build(const Transformation::Shared& _world, const Material::Shared& _material) {
        return std::make_unique<Sphere>(_world, _material);
    }
    Sphere(const Transformation::Shared& _world, const Material::Shared& _material)
      : Figure(_world, _material) {}
    ~Sphere() = default;
    void print(std::ostream& o) const override;
    bool intersects(const Ray& ray, float& depth) const override { return false; }
};

class Box : public Figure {
  public:
    using Unique = std::unique_ptr<Box>;
    static Unique Build(const Transformation::Shared& _world, const Material::Shared& _material) {
        return std::make_unique<Box>(_world, _material);
    }
    Box(const Transformation::Shared& _world, const Material::Shared& _material)
      : Figure(_world, _material) {}
    ~Box() = default;
    void print(std::ostream& o) const override;
    bool intersects(const Ray& ray, float& depth) const override { return false; }
};

class Triangle : public Figure {
  public:
    using Vertex = Vec3f;
    using Unique = std::unique_ptr<Triangle>;
    static Unique Build(
        const Transformation::Shared& _world,
        const Material::Shared& _material,
        const Vertex& _v0,
        const Vertex& _v1,
        const Vertex& _v2) {
        return std::make_unique<Triangle>(_world, _material, _v0, _v1, _v2);
    }
    Triangle(
        const Transformation::Shared& _world,
        const Material::Shared& _material,
        const Vertex& _v0,
        const Vertex& _v1,
        const Vertex& _v2)
      : Figure(_world, _material), v0{_v0}, v1{_v1}, v2{_v2} {}
    ~Triangle() = default;
    void print(std::ostream& o) const override;
    bool intersects(const Ray& ray, float& depth) const override { return false; }

    const Vertex v0;
    const Vertex v1;
    const Vertex v2;
};