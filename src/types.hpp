#pragma once

#include <memory>
#include <tuple>
#include <vector>

#include "camera.hpp"
#include "common.hpp"
#include "figure.hpp"
#include "image.hpp"
#include "light.hpp"

using Transformations = std::vector<Transformation::Shared>;
using Materials       = std::vector<Material::Shared>;
using Lights          = std::vector<Light>;
using Figures         = std::vector<std::unique_ptr<Figure>>;
using Scene           = std::tuple<Image, Camera, Lights, Figures>;