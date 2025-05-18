// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LSystem.generated.h"


UCLASS(Blueprintable)
class LSYSTEMSAMPLE_API ULSystem : public UObject
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tokens")
    UDataTable* TokenDataTable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rules")
    UDataTable* RuleDataTable;

    UFUNCTION(BlueprintCallable, Category = "Tokens")
    FString GetTokenDescription(const FString& TokenID) const;

    UFUNCTION(BlueprintCallable, Category = "Tokens")
    TArray<FString> GetAllTokenIDs() const;

    UFUNCTION(BlueprintCallable, Category = "Rules")
    TArray<FString> GetProductionTokens(const FString& InputToken) const;

    UFUNCTION(BlueprintCallable, Category = "Rules")
    float GetRuleProbability(const FString& InputToken) const;

    UFUNCTION(BlueprintCallable, Category = "Rules")
    TArray<FString> GetAllRuleKeys() const;

    UFUNCTION(BlueprintCallable, Category = "Rules")
    TArray<FLRuleData> GetRulesForToken(const FString& InputToken);

	UFUNCTION(BlueprintCallable, Category = "Generation")
	void ProceedGeneration(TArray<FString> Axiom, int32 Depth, const FPlayerContext& Context, TArray<FString>& Result);
};
