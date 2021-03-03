#pragma once

#include <filesystem>

#include "types.hpp"

class RayTracer {
  public:
    void render(const Scene& scene, const std::filesystem::path& output);
};