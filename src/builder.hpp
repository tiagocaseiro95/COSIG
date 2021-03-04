#pragma once

#include <memory>

template <typename InputType, typename OutputType = InputType>
class Builder {
  public:
    using Shared = std::shared_ptr<OutputType>;
    using Unique = std::unique_ptr<OutputType>;

    template <typename ShareType, typename... Args>
    static std::enable_if_t<std::is_same_v<ShareType, Shared>, Shared> Build(Args&&... args) {
        return std::make_shared<InputType>(std::forward<Args>(args)...);
    }

    template <typename ShareType, typename... Args>
    static std::enable_if_t<std::is_same_v<ShareType, Unique>, Unique> Build(Args&&... args) {
        return std::make_unique<InputType>(std::forward<Args>(args)...);
    }
};