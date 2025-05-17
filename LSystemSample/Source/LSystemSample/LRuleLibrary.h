// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LRuleLibrary.generated.h"


UCLASS(Blueprintable)
class LSYSTEMSAMPLE_API ULRuleLibrary : public UObject
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rules")
    UDataTable* RuleDataTable;

    UFUNCTION(BlueprintCallable, Category = "Rules")
    TArray<FString> GetProductionTokens(const FString& InputToken) const;

    UFUNCTION(BlueprintCallable, Category = "Rules")
    float GetRuleProbability(const FString& InputToken) const;

    UFUNCTION(BlueprintCallable, Category = "Rules")
    TArray<FString> GetAllRuleKeys() const;
};
