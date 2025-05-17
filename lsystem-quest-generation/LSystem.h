#pragma once
#include "LRuleLibrary.h"
#include <random>

class LSystem {
public:
    explicit LSystem(LRuleLibrary& ruleLibrary);
    void ProceedGeneration(std::vector<std::shared_ptr<LToken>>& axiom, int depth, const PlayerContext& context);

private:
    LRuleLibrary& ruleLibrary;
};
