// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LTokenLibrary.generated.h"


UCLASS(Blueprintable)
class LSYSTEMSAMPLE_API ULTokenLibrary : public UObject
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Token Library")
    UDataTable* TokenDataTable;

    UFUNCTION(BlueprintCallable, Category = "Token Library")
    FString GetTokenDescription(const FString& TokenID) const;

    UFUNCTION(BlueprintCallable, Category = "Token Library")
    TArray<FString> GetAllTokenIDs() const;
};
