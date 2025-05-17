// Fill out your copyright notice in the Description page of Project Settings.


#include "LRuleLibrary.h"
#include "Engine/Engine.h"
#include "LRuleData.h"

TArray<FString> ULRuleLibrary::GetProductionTokens(const FString& InputToken) const
{
    TArray<FString> ProductionTokens;
    if (!RuleDataTable) return ProductionTokens;

    static const FString ContextString(TEXT("Rule Lookup"));
    TArray<FName> RowNames = RuleDataTable->GetRowNames();

    for (const FName& RowName : RowNames)
    {
        FLRuleData* Rule = RuleDataTable->FindRow<FLRuleData>(RowName, ContextString);
        if (Rule && Rule->InputToken == InputToken)
        {
            ProductionTokens = Rule->ProductionTokens;
            break;
        }
    }

    return ProductionTokens;
}

float ULRuleLibrary::GetRuleProbability(const FString& InputToken) const
{
    if (!RuleDataTable) return 0.0f;

    static const FString ContextString(TEXT("Rule Probability Lookup"));
    TArray<FName> RowNames = RuleDataTable->GetRowNames();

    for (const FName& RowName : RowNames)
    {
        FLRuleData* Rule = RuleDataTable->FindRow<FLRuleData>(RowName, ContextString);
        if (Rule && Rule->InputToken == InputToken)
        {
            return Rule->BaseProbability;
        }
    }

    return 0.0f;
}

TArray<FString> ULRuleLibrary::GetAllRuleKeys() const
{
    TArray<FString> Keys;
    if (!RuleDataTable) return Keys;

    TArray<FName> RowNames = RuleDataTable->GetRowNames();
    for (const FName& RowName : RowNames)
    {
        Keys.Add(RowName.ToString());
    }

    return Keys;
}