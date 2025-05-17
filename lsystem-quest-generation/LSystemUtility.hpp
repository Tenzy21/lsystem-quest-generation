#pragma once
#include <string>
#include <memory>

#include "LToken.h"

struct LTokenHasher {
    size_t operator()(const std::shared_ptr<LToken>& token) const {
        return std::hash<std::string>()(token->ToString());
    }
};

struct LTokenEqual {
    bool operator()(const std::shared_ptr<LToken>& lhs, const std::shared_ptr<LToken>& rhs) const {
        return lhs->ToString() == rhs->ToString();
    }
};