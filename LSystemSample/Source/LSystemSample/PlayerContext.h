// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerContext.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct LSYSTEMSAMPLE_API FPlayerContext
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    TMap<FString, FString> Preferences;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    int32 Level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
    FString CurrentLocation;
};
