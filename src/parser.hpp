#pragma once

#include <filesystem>

#include "types.hpp"

namespace Parser {

Scene Run(const std::filesystem::path& path);

}; // namespace Parser