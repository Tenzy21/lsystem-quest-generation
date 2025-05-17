// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LToken.h"
#include "TaskToken.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class LSYSTEMSAMPLE_API UTaskToken : public ULToken
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Task")
    FString Description;

    virtual FString ToString() const override { return Description; }
};
