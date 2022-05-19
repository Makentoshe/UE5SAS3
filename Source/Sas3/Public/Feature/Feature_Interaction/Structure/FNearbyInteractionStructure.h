// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Sas3/Public/Actor/GameItemActor.h>
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	NearbyInteractionType NearbyInteractionType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AGameItemActor> Actor;

	FNearbyInteractionStructure();
};
