#pragma once
#include "LToken.h"

class TaskToken : public LToken {
public:
    explicit TaskToken(const std::string& description);
    std::string ToString() const override;

private:
    std::string description;
};
