#include "parser.hpp"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iterator>
#include <numeric>
#include <optional>
#include <vector>

#include "common.hpp"

namespace Parser {

namespace fs     = std::filesystem;
namespace ranges = std::ranges;

auto constexpr END_CHAR = "}";

static inline auto ReadColor(const std::string& line) {
    auto is  = std::istringstream{line};
    auto itr = std::istream_iterator<float>(is);

    auto r = u_char(*itr * 255);
    std::next(itr);
    auto g = u_char(*itr * 255);
    std::next(itr);
    auto b = u_char(*itr * 255);

    auto color = Color(r, g, b);
    return color;
}

static auto ReadImage(std::fstream& file) {
    auto line = std::string{};

    std::getline(file, line);
    auto height = int{};
    auto width  = int{};
    auto is     = std::istringstream{line};
    is >> width >> height;

    std::getline(file, line);
    auto color = ReadColor(line);

    return Image(width, height, color);
}

static auto ReadTransformation(std::fstream& file) {
    auto matrices = std::vector<Matrix44f>();
    for (auto line = std::string{}; std::getline(file, line) && line != END_CHAR;) {
        auto is   = std::istringstream{line};
        auto type = std::string{};
        is >> type;
        if (type == "S") {
            auto x = float{};
            auto y = float{};
            auto z = float{};
            is >> x >> y >> z;
            matrices.emplace_back(Transformation::Scale(x, y, z));
        } else if (type == "T") {
            auto x = float{};
            auto y = float{};
            auto z = float{};
            is >> x >> y >> z;
            matrices.emplace_back(Transformation::Translation(x, y, z));
        } else if (type == "Rx") {
            auto angle = float{};
            is >> angle;
            matrices.emplace_back(Transformation::RotationX(angle));
        } else if (type == "Ry") {
            auto angle = float{};
            is >> angle;
            matrices.emplace_back(Transformation::RotationY(angle));
        } else if (type == "Rz") {
            auto angle = float{};
            is >> angle;
            matrices.emplace_back(Transformation::RotationZ(angle));
        }
    }
    auto matrix = std::reduce(
        std::cbegin(matrices), std::cend(matrices), Matrix44f{}, std::multiplies{});
    return Transformation::Build<Transformation::Shared>(matrix);
}

static auto ReadMaterial(std::fstream& file) {
    auto line = std::string{};

    std::getline(file, line);
    auto color = ReadColor(line);

    std::getline(file, line);
    auto ambient_cof      = float{};
    auto diffuse_cof      = float{};
    auto reflection_cof   = float{};
    auto refraction_cof   = float{};
    auto refraction_index = float{};
    auto is               = std::istringstream{line};
    is >> ambient_cof >> diffuse_cof >> reflection_cof >> refraction_cof >> refraction_index;

    return Material::Build<Material::Shared>(
        color, ambient_cof, diffuse_cof, reflection_cof, refraction_cof, refraction_index);
}

static auto ReadCamera(std::fstream& file, const Transformations& transformations) {
    auto line = std::string{};

    std::getline(file, line);
    auto index = int{};
    auto is    = std::istringstream{line};
    is >> index;
    auto transformation = transformations[index];

    std::getline(file, line);
    auto distance = float{};
    is            = std::istringstream{line};
    is >> distance;

    std::getline(file, line);
    auto fov = float{};
    is       = std::istringstream{line};
    is >> fov;

    return Camera(
        Transformation::Build<Transformation::Shared>(transformation->inverse()), distance, fov);
}

static auto ReadLight(std::fstream& file, const Transformations& transformations) {
    auto line = std::string{};

    std::getline(file, line);
    auto index = int{};
    auto is    = std::istringstream{line};
    is >> index;
    auto transformation = transformations[index];

    std::getline(file, line);
    auto color = ReadColor(line);

    return Light(transformation, color);
}

static auto
ReadSphere(std::fstream& file, const Transformations& transformations, const Materials& materials) {
    auto line = std::string{};

    std::getline(file, line);
    auto index = int{};
    auto is    = std::istringstream{line};
    is >> index;
    auto transformation = transformations[index];

    std::getline(file, line);
    is = std::istringstream{line};
    is >> index;
    auto material = materials[index];

    return Sphere::Build<Sphere::Unique>(transformation, material);
}

static auto
ReadBox(std::fstream& file, const Transformations& transformations, const Materials& materials) {
    auto line = std::string{};

    std::getline(file, line);
    auto index = int{};
    auto is    = std::istringstream{line};
    is >> index;
    auto transformation = transformations[index];

    std::getline(file, line);
    is = std::istringstream{line};
    is >> index;
    auto material = materials[index];

    return Box::Build<Box::Unique>(transformation, material);
}

static inline auto ReadVertex(std::fstream& file) {
    auto line = std::string{};
    std::getline(file, line);
    auto vertex = Vec3f();
    auto is     = std::istringstream{line};
    is >> vertex[0] >> vertex[1] >> vertex[2];
    return vertex;
}

static inline auto
ReadTriangle(std::fstream& file, Transformation::Shared transformation, Material::Shared material) {
    auto v0 = ReadVertex(file);
    auto v1 = ReadVertex(file);
    auto v2 = ReadVertex(file);
    return Triangle::Build<Triangle::Unique>(transformation, material, v0, v1, v2);
}

static auto ReadTriangles(
    std::fstream& file,
    const Transformations& transformations,
    const Materials& materials) {
    auto line = std::string{};

    std::getline(file, line);
    auto index = int{};
    auto is    = std::istringstream{line};
    is >> index;

    auto transformation = transformations[index];
    auto triangles      = std::vector<Triangle::Unique>{};

    while (std::getline(file, line) && line != END_CHAR) {
        is = std::istringstream{line};
        is >> index;
        auto material = materials[index];
        triangles.emplace_back(ReadTriangle(file, transformation, material));
    }

    return triangles;
}

Scene Run(const fs::path& path) {
    auto file            = std::fstream(path);
    auto transformations = Transformations();
    auto materials       = Materials();
    auto figures         = Figures();
    auto lights          = Lights();
    auto image           = std::optional<Image>(std::nullopt);
    auto camera          = std::optional<Camera>(std::nullopt);
    auto skipLine        = [&file]() {
        auto tmp = std::string{};
        std::getline(file, tmp);
    };

    for (auto line = std::string{}; std::getline(file, line);) {
        auto name = std::string{};
        auto is   = std::istringstream{line};
        is >> name;

        if (name == "Image") {
            skipLine();
            image.emplace(ReadImage(file));
        } else if (name == "Transformation") {
            skipLine();
            transformations.emplace_back(ReadTransformation(file));
        } else if (name == "Material") {
            skipLine();
            materials.emplace_back(ReadMaterial(file));
        } else if (name == "Camera") {
            skipLine();
            camera.emplace(ReadCamera(file, transformations));
        } else if (name == "Light") {
            skipLine();
            lights.emplace_back(ReadLight(file, transformations));
        } else if (name == "Sphere") {
            skipLine();
            figures.emplace_back(ReadSphere(file, transformations, materials));
        } else if (name == "Box") {
            skipLine();
            figures.emplace_back(ReadBox(file, transformations, materials));
        } else if (name == "Triangles") {
            skipLine();
            ranges::move(
                ReadTriangles(file, transformations, materials), std::back_inserter(figures));
        }
    }

    if (!image)
        throw std::runtime_error("Missing image data");
    if (!camera)
        throw std::runtime_error("Missing camera data");

    return {*image, *camera, std::move(lights), std::move(figures)};
}
} // namespace Parser