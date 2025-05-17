// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LToken.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class LSYSTEMSAMPLE_API ULToken : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Token")
	virtual FString ToString() const { return "Base Token"; }
};
