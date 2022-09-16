// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "FInventorableComponentSaveload.generated.h"

/**
 * Wrapper for holding info about InventorableComponent for serialization/deserialization.
 */
USTRUCT(BlueprintType)
struct SAS3_API FInventorableComponentSaveload
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, SaveGame)
	int32 ItemCount;

	UPROPERTY(BlueprintReadWrite, SaveGame)
	int32 StackSize;

	FInventorableComponentSaveload();

	virtual ~FInventorableComponentSaveload();
};