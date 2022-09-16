// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FInventoryMetaStructure.generated.h"

/**
 * Meta structure works with GameItemStructure that allows
 * to understand inventory preferences for this item.
 */
USTRUCT(BlueprintType)
struct SAS3_API FInventoryMetaStructure : public FTableRowBase
{
	GENERATED_BODY()

	// Contains how many items is in the current instance
	// Note: uint32 isn't supported by blueprint, so be careful about negative values
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ItemCount;

	// How many items might be in one stack. Each new stack consumes an inventory slot
	// Note: uint32 isn't supported by blueprint, so be careful about negative values
	// Note: if we don't want item to be stackable, this value should be equal 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StackSize;

	FInventoryMetaStructure();

	FInventoryMetaStructure(int32 ItemCount, int32 StackSize);

	// Note: virtual for the super call
	virtual ~FInventoryMetaStructure();

	// Allows to assign an object using = operator.
	// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
	FInventoryMetaStructure& operator=(const FInventoryMetaStructure Structure);
};
