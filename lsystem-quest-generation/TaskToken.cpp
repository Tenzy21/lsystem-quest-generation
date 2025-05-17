#include "TaskToken.h"

TaskToken::TaskToken(const std::string& description) : description(description) {}

std::string TaskToken::ToString() const {
    return description;
}
