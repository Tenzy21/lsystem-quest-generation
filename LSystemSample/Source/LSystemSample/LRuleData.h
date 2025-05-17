// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LRuleData.generated.h"

USTRUCT(BlueprintType)
struct LSYSTEMSAMPLE_API FLRuleData : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rule")
    FString InputToken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rule")
    TArray<FString> ProductionTokens;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rule")
    float BaseProbability; 
};
