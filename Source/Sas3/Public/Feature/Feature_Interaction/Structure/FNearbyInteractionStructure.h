// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Sas3/Public/Items/Items/Actors/GameItemActor.h>
#include <Sas3/Public/Feature/Features/Enums/ENearbyInteractionType.h>
#include "FNearbyInteractionStructure.generated.h"

/**
 * Structure contains default parameters for any item in the game
 */
USTRUCT(BlueprintType)
struct SAS3_API FNearbyInteractionStructure
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

	// Reference to the Actor that should be acted
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AGameItemActor> Actor;

	// Default constructor
	FNearbyInteractionStructure();

	// Default virtual desrtuctor
	virtual ~FNearbyInteractionStructure();

	// Allows to assign an object using = operator.
	// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
	FNearbyInteractionStructure& operator=(const FNearbyInteractionStructure Structure);

	// Allows to compare 2 Structures
	// Note: here we checking actors only, because this structures cant be unassigned from the provided actors
	// So, if actors are equal -> structures also equal
	bool operator==(const FNearbyInteractionStructure& Structure);

	// Allows to compare 2 Structures
	// Note: here we checking actors only, because this structures cant be unassigned from the provided actors
	// So, if actors aren't equal -> structures also not equal
	bool operator!=(const FNearbyInteractionStructure& Structure);
};
