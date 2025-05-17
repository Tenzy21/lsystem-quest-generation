#pragma once
#include "LToken.h"
#include "PlayerContext.h"
#include <vector>
#include <functional>

using Predicate = std::function<float(const PlayerContext&)>;

class LRule {
public:
    LRule(const std::shared_ptr<LToken>& inputToken,
        const std::vector<std::shared_ptr<LToken>>& production,
        float baseProbability = 1.0f);

    void AddPredicate(Predicate pred);
    float GetApplyProbability(const PlayerContext& context) const;

    const std::shared_ptr<LToken>& GetInputToken() const;
    const std::vector<std::shared_ptr<LToken>>& GetProduction() const;

private:
    std::shared_ptr<LToken> inputToken;
    std::vector<std::shared_ptr<LToken>> production;
    std::vector<Predicate> predicates;
    float baseProbability;
};
