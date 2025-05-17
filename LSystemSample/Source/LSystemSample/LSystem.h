// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LSystem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class LSYSTEMSAMPLE_API ULSystem : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Generation")
	void ProceedGeneration(TArray<ULToken*>& Axiom, int32 Depth, const FPlayerContext& Context);
};
