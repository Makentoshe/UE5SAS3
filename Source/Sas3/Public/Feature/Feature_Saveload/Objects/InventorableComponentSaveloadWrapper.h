// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "InventorableComponentSaveloadWrapper.generated.h"

/**
 * Wrapper for holding info about InventorableComponent for serialization.
 */
UCLASS(BlueprintType)
class SAS3_API UInventorableComponentSaveloadWrapper : public UObject
{
	GENERATED_BODY()

public: 

	UPROPERTY(BlueprintReadWrite, SaveGame)
	int32 ItemCount;

	UPROPERTY(BlueprintReadWrite, SaveGame)
	int32 StackSize;
};
