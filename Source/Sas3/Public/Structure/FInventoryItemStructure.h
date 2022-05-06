// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FInventoryItemStructure.generated.h"

/**
 * Structure contains valuable parameters for inventory feature
 */
USTRUCT(BlueprintType)
struct FInventoryItemStructure
{
	GENERATED_BODY()

	// Contains the item name that will be displayed in the inventory UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Title;

	// Contains how many items in the current instance
	// Note: uint32 isn't supported by blueprint, so be careful about negative values
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count;

	// If item isn't stackable each new item in the inventory will consume a new slot.
	// If item is stackable they will try to stack between each other and will consume 
	// a new slot if all stacks are full.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsStacking;

	// Default constructor
	FInventoryItemStructure();

	// Default destructor
	~FInventoryItemStructure();
};
