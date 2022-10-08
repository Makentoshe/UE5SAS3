// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryItemStructure.h>

#include "FInventoryComponentSaveload.generated.h"

/**
 * Wrapper for holding info about InventorableComponent for serialization/deserialization.
 */
USTRUCT(BlueprintType)
struct SAS3_API FInventoryComponentSaveload
{
	GENERATED_BODY()

public:

	// Defines how many stacks of items might be in the inventory
	UPROPERTY(BlueprintReadWrite, SaveGame)
	int32 InventorySize;

	// Contains all items in the inventory
	UPROPERTY(BlueprintReadWrite, SaveGame)
	TArray<FInventoryItemStructure> InventoryItems;
	
	FInventoryComponentSaveload();

	virtual ~FInventoryComponentSaveload();
};
