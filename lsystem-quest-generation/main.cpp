#include <iostream>
#include <fstream>
#include <chrono>
#include "PlayerContext.h"
#include "TaskToken.h"
#include "LRuleLibrary.h"
#include "LSystem.h"
#include "TaskTokenLibrary.h"

void ProceedGenerationLogged(
    std::vector<std::shared_ptr<LToken>> axiom,
    int depth,
    const PlayerContext& context,
    const LRuleLibrary& ruleLibrary,
    const std::string& outputCsv,
    int runIndex
) {
    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream csv(outputCsv, std::ios::app);
    csv << "Run,Step,Token,Weight,Time\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::unordered_map<std::string, float> tokenWeights;

    for (const auto& token : axiom)
        tokenWeights[token->ToString()] = 1.0f;

    for (int i = 0; i <= depth; ++i) {
        for (const auto& token : axiom) {
            csv << runIndex << "," << i << "," << token->ToString() << "," << tokenWeights[token->ToString()];

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            csv << "," << duration.count();

            csv << "\n";
        }

        if (i == depth) break;

        std::vector<std::shared_ptr<LToken>> newResult;
        std::unordered_map<std::string, float> newWeights;

        for (const auto& token : axiom) {
            bool applied = false;
            float prevWeight = tokenWeights[token->ToString()];
            const auto& rules = ruleLibrary.GetRulesForToken(token);

            for (const auto& rule : rules) {
                float prob = rule->GetApplyProbability(context);
                if (dis(gen) < prob) {
                    for (const auto& prod : rule->GetProduction()) {
                        newResult.push_back(prod);
                        newWeights[prod->ToString()] = prevWeight * prob;
                    }
                    applied = true;
                    break;
                }
            }

            if (!applied) {
                newResult.push_back(token);
                newWeights[token->ToString()] = prevWeight;
            }
        }

        axiom = newResult;
        tokenWeights = newWeights;
    }

    csv.close();
}

int main() {
    PlayerContext context;
    context.preferences["combat"] = "no";
    context.level = 7;
    context.currentLocation = "Castle";

    TaskTokenLibrary lib;
    LRuleLibrary ruleLib(lib);
    LSystem lsystem(ruleLib);
    std::vector<std::shared_ptr<LToken>> axiom = { lib.Find("S") };
    int testRuns = 1000;
    std::vector<int> depths = { 3, 5, 7, 10 };

    int enterMode;
    std::cout << "Type run option:" << std::endl;
    std::cout << "[0] - Default run" << std::endl;
    std::cout << "[1] - Collect test data in csv" << std::endl;
    std::cin >> enterMode;

    switch (enterMode)
    {
    case 0:
        lsystem.ProceedGeneration(axiom, 5, context);

        std::cout << "Generation completed." << std::endl;
        for (auto token : axiom) {
            std::cout << token.get()->ToString() << " ";
        }
        break;
    case 1:
        for (int run = 0; run < testRuns; ++run) {
            for (int depth : depths) {
                axiom = { lib.Find("S") };
                ProceedGenerationLogged(axiom, depth, context, ruleLib, "generations.csv", run * 100 + depth);
            }
        }

        std::cout << "Generation completed: generations.csv" << std::endl;
        break;
    default:
        std::cout << "Unknown run";
        return 69;
    }


    return 0;
}

