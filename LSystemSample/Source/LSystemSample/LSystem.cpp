// Fill out your copyright notice in the Description page of Project Settings.


#include "LSystem.h"

void ULSystem::ProceedGeneration(TArray<ULToken*>& Axiom, int32 Depth, const FPlayerContext& Context)
{
    for (int32 i = 0; i < Depth; ++i)
    {
        TArray<ULToken*> NewResult;
        for (ULToken* Token : Axiom)
        {
            NewResult.Add(Token);
        }
        Axiom = NewResult;
    }
}
