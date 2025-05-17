// Fill out your copyright notice in the Description page of Project Settings.


#include "LTokenLibrary.h"
#include "LTokenData.h"

FString ULTokenLibrary::GetTokenDescription(const FString& TokenID) const
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

TArray<FString> ULTokenLibrary::GetAllTokenIDs() const
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
