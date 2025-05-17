#include "LRuleLibrary.h"

LRuleLibrary::LRuleLibrary(TaskTokenLibrary lib)
{
    Add(lib.Find("S"), { lib.Find("[START]"), lib.Find("H"), lib.Find("T"), lib.Find("R"), lib.Find("G"), lib.Find("[END]") }, 1.0f);
    Add(lib.Find("H"), { lib.Find("{C}"), lib.Find("{L}"), lib.Find("{P}") }, 0.5f);
    Add(lib.Find("T"), { lib.Find("T"), lib.Find("[THEN]"), lib.Find("T") }, 0.3f);
    Add(lib.Find("R"), { lib.Find("R"), lib.Find("R") }, 0.3f);
    Add(lib.Find("G"), { lib.Find("G"), lib.Find("G") }, 0.3f);
    Add(lib.Find("T"), { lib.Find("{A_I}"), lib.Find("{I}") }, 0.2f);
    Add(lib.Find("T"), { lib.Find("{A_C}"), lib.Find("{C}") }, 0.35f);
    Add(lib.Find("T"), { lib.Find("{A_L}"), lib.Find("{L}") }, 0.3f);
    Add(lib.Find("T"), { lib.Find("{A}") }, 0.22f);
    Add(lib.Find("R"), { lib.Find("{R_E}"), lib.Find("{C}") }, 0.3f);
    Add(lib.Find("R"), { lib.Find("{R_P}") }, 0.2f);
    Add(lib.Find("R"), { lib.Find("{R_T}") }, 0.2f);
    Add(lib.Find("G"), { lib.Find("{P}"), lib.Find("[THEN]"), lib.Find("T") }, 0.15f);
    Add(lib.Find("G"), { lib.Find("{G_I}") }, 0.45f);
    Add(lib.Find("G"), { lib.Find("{G_E}") }, 0.45f);
    Add(lib.Find("G"), { lib.Find("{G_G}") }, 0.45f);
    Add(lib.Find("[END]"), { lib.Find("[END]"), lib.Find("[THEN]"), lib.Find("S") }, 0.12f);
}

void LRuleLibrary::Add(std::shared_ptr<LToken> inputToken, std::vector<std::shared_ptr<LToken>> production, float baseProbability)
{
	Add(LRule(inputToken, production, baseProbability));
}

void LRuleLibrary::Add(const LRule& rule)
{
    rules[rule.GetInputToken()].push_back(std::make_shared<LRule>(rule));
}

const std::vector<std::shared_ptr<LRule>>& LRuleLibrary::GetRulesForToken(const std::shared_ptr<LToken>& token) const
{
    static std::vector<std::shared_ptr<LRule>> empty;
    auto it = rules.find(token);
    return (it != rules.end()) ? it->second : empty;
}