#pragma once

#include <memory>

template <typename InputType, typename OutputType = InputType>
class Builder {
  public:
    using Shared = std::shared_ptr<OutputType>;
    using Unique = std::unique_ptr<OutputType>;


    template <typename Result = Shared, typename... Args>
    static Result Build(Args&&... args) {
        return std::make_unique<InputType>(std::forward<Args>(args)...);
    }
};
