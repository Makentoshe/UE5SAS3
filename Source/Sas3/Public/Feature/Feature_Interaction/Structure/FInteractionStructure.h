// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include <Sas3/Public/Feature/Features/Enums/ENearbyInteractionType.h>
#include "FInteractionStructure.generated.h"

/**
 * Structure contains info about interaction
 */
USTRUCT(BlueprintType)
struct SAS3_API FInteractionStructure: public FTableRowBase
{
	GENERATED_BODY()

	// Contains the item name that will be displayed to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Title;

	// Contains the item name that will be displayed to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Description;

	// Contains the interaction type that may help to understand how interaction should be acted
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	NearbyInteractionType NearbyInteractionType;

	// Default constructor
	FInteractionStructure();

	// Default virtual desrtuctor
	~FInteractionStructure();

	// Allows to assign an object using = operator.
	// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
	FInteractionStructure& operator=(const FInteractionStructure Structure);

	// Allows to compare 2 Structures
	bool operator==(const FInteractionStructure& Structure);

	// Allows to compare 2 Structures
	bool operator!=(const FInteractionStructure& Structure);
};
