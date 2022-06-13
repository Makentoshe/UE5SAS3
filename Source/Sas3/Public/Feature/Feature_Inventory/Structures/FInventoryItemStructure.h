// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Feature/Features/Structures/FGameItemStructure.h"
#include "FInventoryItemStructure.generated.h"

/**
 * Structure contains valuable parameters for inventory feature
 */
USTRUCT(BlueprintType)
struct SAS3_API FInventoryItemStructure: public FGameItemStructure
{
	GENERATED_BODY()

	// Contains how many items is in the current instance
	// Note: uint32 isn't supported by blueprint, so be careful about negative values
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count;

	// How many items might be in one stack. Each new stack consumes an inventory slot
	// Note: uint32 isn't supported by blueprint, so be careful about negative values
	// Note: if we don't want item to be stackable, this value should be equal 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metainfo")
	int32 StackSize;

	// Default constructor
	FInventoryItemStructure();

	virtual ~FInventoryItemStructure();

	// Copying constructor with new Count parameter
	FInventoryItemStructure(const FInventoryItemStructure& Structure, int32 Count);

	// Allows to assign an object using = operator.
	// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
	FInventoryItemStructure& operator=(const FInventoryItemStructure Structure);
};
