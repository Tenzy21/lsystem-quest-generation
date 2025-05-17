#pragma once
#include "LRule.h"
#include "TaskTokenLibrary.h"
#include "LSystemUtility.hpp"

class LRuleLibrary {
public:
    LRuleLibrary(TaskTokenLibrary lib);

    void Add(std::shared_ptr<LToken> inputToken, std::vector<std::shared_ptr<LToken>> production, float baseProbability = 1.0f);
    void Add(const LRule& rule);
    const std::vector<std::shared_ptr<LRule>>& GetRulesForToken(const std::shared_ptr<LToken>& token) const;
    std::unordered_map<std::shared_ptr<LToken>, std::vector<std::shared_ptr<LRule>>, LTokenHasher, LTokenEqual> rules;
};