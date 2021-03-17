#include <chrono>
#include <iostream>

#include <boost/program_options.hpp>

#include "parser.hpp"
#include "raytracer.hpp"
#include "types.hpp"

namespace po = boost::program_options;

void Render(const Scene& scene);

int main(int ac, char const* av[]) {
    auto path = std::string{};

    auto p = po::positional_options_description();
    p.add("scene", -1);

    auto desc = po::options_description("Allowed options");
    desc.add_options()("help", "produce help message")(
        "scene", po::value<std::string>(&path), "set scene file path");

    auto vm = po::variables_map();
    po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (!vm.count("scene")) {
        std::cout << "Scene file must be set" << std::endl;
        return 1;
    }
    auto scene      = Parser::Run(path);
    auto ray_tracer = RayTracer();
    auto now        = std::chrono::steady_clock::now();
    ray_tracer.render(scene, "output.ppm");
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Time elapsed: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << " ms"
              << std::endl;

    return 0;
}
