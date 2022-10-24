// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryItemStructure.h>

#include "FSaveloadJsonStructure.generated.h"

/**
 * Structure for storing info about actor in Json
 */
USTRUCT(BlueprintType)
struct SAS3_API FSaveloadJsonStructure
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, SaveGame)
	int32 InventorableComponentItemCount;

	UPROPERTY(BlueprintReadWrite, SaveGame)
	int32 InventorableComponentStackSize;

	UPROPERTY(BlueprintReadWrite, SaveGame)
	int32 InventoryComponentInventorySize;

	UPROPERTY(BlueprintReadWrite, SaveGame)
	TArray<FInventoryItemStructure> InventoryComponentInventoryItems;


	FSaveloadJsonStructure();

	virtual ~FSaveloadJsonStructure();
};
