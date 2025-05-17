#pragma once
#include <string>
#include <memory>

class LToken {
public:
    virtual ~LToken() = default;
    virtual std::string ToString() const { return ""; }
};
