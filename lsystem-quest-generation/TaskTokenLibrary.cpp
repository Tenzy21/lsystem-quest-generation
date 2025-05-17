#include "TaskTokenLibrary.h"

using TokenPtr = std::shared_ptr<TaskToken>;

TaskTokenLibrary::TaskTokenLibrary()
{
    Add("S"); //Start token
    Add("H"); //Hook
    Add("T"); //Task
    Add("R"); //Resistance
    Add("G"); //Goal (Reward)
    Add("{I}"); //Item
    Add("{C}"); //Character
    Add("{L}"); //Location
    Add("{P}"); //Problem (Description)
    Add("{A_I}"); //Action with item
    Add("{A_C}"); //Action with character
    Add("{A_L}"); //Action with location
    Add("{A}"); //Action (common)
    Add("{R_E}"); //Resistance by enemy
    Add("{R_P}"); //Resistance by puzzle
    Add("{R_T}"); //Resistance by trap
    Add("{G_I}"); //Goal is item
    Add("{G_E}"); //Goal is exp
    Add("{G_G}"); //Goal is gold
    Add("[START]"); //Utility token - Objective start
    Add("[END]"); //Utility token - Objective end
    Add("[THEN]"); //Utility token - Tasks chaining
    Add("[SKIP]"); //Utility token - No matter
}

void TaskTokenLibrary::Add(const std::string& tokenString)
{
    if (!Contains(tokenString))
        tokens.push_back(std::make_shared<TaskToken>(tokenString));
}

void TaskTokenLibrary::Remove(const std::string& tokenString)
{
    auto it = std::find_if(tokens.begin(), tokens.end(),
        [&](const TokenPtr& token) { return token->ToString() == tokenString; });

    if (it != tokens.end())
        tokens.erase(it);
}

bool TaskTokenLibrary::Contains(const std::string& tokenString) const
{
    return std::any_of(tokens.begin(), tokens.end(),
        [&](const TokenPtr& token) { return token->ToString() == tokenString; });
}

TokenPtr TaskTokenLibrary::Find(const std::string& tokenString) const
{
    auto it = std::find_if(tokens.begin(), tokens.end(),
        [&](const TokenPtr& token) { return token->ToString() == tokenString; });

    if (it != tokens.end())
        return *it;

    return nullptr;
}