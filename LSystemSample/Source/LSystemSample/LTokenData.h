// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviourClassification.h"
#include "LTokenData.generated.h"


USTRUCT(BlueprintType)
struct LSYSTEMSAMPLE_API FLTokenData : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Token")
    FString TokenID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Token")
    TSoftObjectPtr<UObject> LinkedObject;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Token")
    FString Description;    
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Token")
    float Weight = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Token")
    TMap<EBehaviourClassification, float> CategorizedWeights;
};
