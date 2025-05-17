#pragma once
#include <unordered_map>
#include <string>

struct PlayerContext {
    std::unordered_map<std::string, std::string> preferences;
    int level;
    std::string currentLocation;
};
