#include "raytracer.hpp"

#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <ranges>

#include "geometry.hpp"
namespace views = std::views;

static auto CreateRay(int row, int col, const Image& image, const Camera& camera) {
    auto ratio  = image.width / (float)image.height;
    auto ndc    = Vec2(col / (float)image.width, row / (float)image.height);
    auto screen = Vec2f(
        (2 * ndc.x - 1) * ratio * std::tan(camera.fov / 2) * camera.distance,
        (1 - 2 * ndc.y) * std::tan(camera.fov / 2) * camera.distance);

    auto origin    = Vec3f();
    auto direction = Vec3f(screen.x, screen.y, -camera.distance);

    camera.world->multVecMatrix(origin, origin);
    camera.world->multDirMatrix(direction, direction);

    origin.normalize();
    direction.normalize();

    return Ray(origin, direction);
}

void RayTracer::render(const Scene& scene, const std::filesystem::path& output) {
    auto& [image, camera, lights, figures] = scene;
    auto pixel_count                       = image.width * image.height;
    auto frame_buffer                      = std::vector<Color>(pixel_count, image.color);
    auto depth_buffer = std::vector<float>(pixel_count, std::numeric_limits<float>::max());
    for (int row : views::iota(0) | views::take(image.height)) {
        for (int col : views::iota(0) | views::take(image.width)) {
            auto ray = CreateRay(row + .5f, col + .5f, image, camera);
            std::cout << "row: " << row << std::endl;
            std::cout << "col: " << col << std::endl;
            std::cout << ray << std::endl << std::endl;
            // TODO: Fix wrong index
            auto index = row * image.width + col;
            for (const auto& figure : figures)
                if (figure->intersects(ray, depth_buffer[index]))
                    frame_buffer[index] = figure->material->color;
            // if (col == 0)
            //     break;
        }
        // if (row == 0)
        //     break;
    }



    auto ofs = std::ofstream(output);
    ofs << "P5\n" << image.width << " " << image.height << "\n255\n";
    ofs.write((char*)frame_buffer.data(), pixel_count * 3);

} // namespace RayTracer
