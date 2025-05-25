// Fill out your copyright notice in the Description page of Project Settings.


#include "LSystem.h"
#include "LRuleData.h"
#include "LTokenData.h"

FString ULSystem::GetTokenDescription(const FString& TokenID) const
{
    if (!TokenDataTable) return "DataTable is null!";

    static const FString ContextString(TEXT("Token Lookup"));

    FLTokenData* TokenData = TokenDataTable->FindRow<FLTokenData>(FName(*TokenID), ContextString);
    if (TokenData)
    {
        return TokenData->Description;
    }
    return "Token not found!";
}

TArray<FString> ULSystem::GetAllTokenIDs() const
{
    TArray<FString> TokenIDs;

    if (!TokenDataTable) return TokenIDs;

    TArray<FName> RowNames = TokenDataTable->GetRowNames();
    for (const FName& RowName : RowNames)
    {
        TokenIDs.Add(RowName.ToString());
    }

    return TokenIDs;
}

TArray<FString> ULSystem::GetProductionTokens(const FString& InputToken) const
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

float ULSystem::GetRuleProbability(const FString& InputToken) const
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

TArray<FString> ULSystem::GetAllRuleKeys() const
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

TArray<FLRuleData> ULSystem::GetRulesForToken(const FString& InputToken)
{
    TArray<FLRuleData> MatchingRules;
    if (!RuleDataTable) return MatchingRules;

    static const FString ContextString(TEXT("Rule Lookup"));
    TArray<FName> RowNames = RuleDataTable->GetRowNames();

    for (const FName& RowName : RowNames)
    {
        FLRuleData* Rule = RuleDataTable->FindRow<FLRuleData>(RowName, ContextString);
        if (Rule && Rule->InputToken == InputToken)
        {
            MatchingRules.Add(*Rule);
        }
    }

    return MatchingRules;
}

void ULSystem::ProceedGeneration(TArray<FString> Axiom, int32 Depth, const FPlayerContext& Context, TArray<FString>& Result)
{
    GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("LSystem message: Generation started"));

    if (!RuleDataTable)
    {
        UE_LOG(LogTemp, Error, TEXT("RuleDataTable is not set!"));
        return;
    }

    Result = Axiom;
    for (int32 Iteration = 0; Iteration < Depth; ++Iteration)
    {
        UE_LOG(LogTemp, Log, TEXT("LSystem iteration %d:"), Iteration);
        
        FString LogAxiom;
        for (const auto Token : Result) {
            LogAxiom.Append(*Token);
        }
        UE_LOG(LogTemp, Log, TEXT("Start with axiom %s"), *LogAxiom);

        TArray<FString> NewAxiom;
        for (const auto Token : Result) {
            GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("LSystem message: Proceeded Token - " + Token));

            bool RuleApplied = false;
            TArray<FLRuleData> Rules = GetRulesForToken(Token);

            for (const FLRuleData Rule : Rules)
            {
                float RandomValue = FMath::FRand();
                if (RandomValue < Rule.BaseProbability)
                {
                    NewAxiom.Append(Rule.ProductionTokens);
                    RuleApplied = true;

                    UE_LOG(LogTemp, Log, TEXT("Applied Rule: %s -> %s (Probability: %f)"),
                        *Token, *FString::Join(Rule.ProductionTokens, TEXT(" ")), Rule.BaseProbability);
                    break;
                }
            }

            if (!RuleApplied)
            {
                NewAxiom.Add(Token);
                UE_LOG(LogTemp, Log, TEXT("Token remained unchanged: %s"), *Token);
            }
        }

        Result = NewAxiom;
    }

    for (const auto Token : Axiom)
    {
        UE_LOG(LogTemp, Log, TEXT("Generated Token: %s"), *Token);
    }
}
