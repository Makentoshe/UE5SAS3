// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryItemStructure.h>
#include "UInventoryItemWrapper.generated.h"

/**
 * Just an ordinary wrapper for InventoryItemStructure because some widgets doesn't consume a structure
 */
UCLASS(BlueprintType)
class SAS3_API UInventoryItemWrapper : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInventoryItemStructure InventoryItem;
};
