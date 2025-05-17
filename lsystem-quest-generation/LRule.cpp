#include "LRule.h"

LRule::LRule(const std::shared_ptr<LToken>& inputToken,
    const std::vector<std::shared_ptr<LToken>>& production,
    float baseProbability)
    : inputToken(inputToken), production(production), baseProbability(baseProbability) {}

void LRule::AddPredicate(Predicate pred) {
    predicates.push_back(pred);
}

float LRule::GetApplyProbability(const PlayerContext& context) const {
    float probability = baseProbability;
    for (const auto& pred : predicates) {
        probability *= pred(context);
    }
    return probability;
}

const std::shared_ptr<LToken>& LRule::GetInputToken() const {
    return inputToken;
}

const std::vector<std::shared_ptr<LToken>>& LRule::GetProduction() const {
    return production;
}
