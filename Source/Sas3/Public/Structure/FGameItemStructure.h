// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FGameItemStructure.generated.h"

/**
 * Structure contains default parameters for any item in the game
 */
USTRUCT(BlueprintType)
struct SAS3_API FGameItemStructure
{
	GENERATED_BODY()

	// Contains the item name that will be displayed to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Title;

	// Default constructor
	FGameItemStructure();

	// Default destructor
	~FGameItemStructure();
};
