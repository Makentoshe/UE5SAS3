// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FGameItemStructure.generated.h"

/**
 * Structure contains default parameters for any item in the game
 */
USTRUCT(BlueprintType)
struct SAS3_API FGameItemStructure: public FTableRowBase
{
	GENERATED_BODY()

	// Contains the item name that will be displayed to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Title;

	// Default constructor
	FGameItemStructure();

	// Default destructor
	// Note: virtual for the super call
	virtual ~FGameItemStructure();

	FGameItemStructure& operator=(const FGameItemStructure Structure);

};
