#include "LSystem.h"

LSystem::LSystem(LRuleLibrary& ruleLibrary) : ruleLibrary(ruleLibrary) {}

void LSystem::ProceedGeneration(std::vector<std::shared_ptr<LToken>>& axiom, int depth, const PlayerContext& context) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < depth; ++i) {
        std::vector<std::shared_ptr<LToken>> newResult;

        for (auto& token : axiom) {
            bool applied = false;
            const auto& rules = ruleLibrary.GetRulesForToken(token);

            for (const auto& rule : rules) {
                if (dis(gen) < rule->GetApplyProbability(context)) {
                    newResult.insert(newResult.end(), rule->GetProduction().begin(), rule->GetProduction().end());
                    applied = true;
                    break;
                }
            }

            if (!applied) {
                newResult.push_back(token);
            }
        }

        axiom = newResult;
    }
}
