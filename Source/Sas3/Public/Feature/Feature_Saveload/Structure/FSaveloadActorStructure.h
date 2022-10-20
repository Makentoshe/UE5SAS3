// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <Sas3/Public/Feature/Feature_Saveload/Objects/FInventorableComponentSaveload.h>
#include <Sas3/Public/Feature/Feature_Saveload/Objects/FInventoryComponentSaveload.h>

#include "FSaveloadActorStructure.generated.h"

/**
 * Structure for storing info about actors.
 */
USTRUCT(BlueprintType)
struct SAS3_API FSaveloadActorStructure
{

	GENERATED_BODY()

public:

	/* Identifier for which Actor this belongs to */
	UPROPERTY(BlueprintReadWrite)
	FName ActorIdentifier;

	/* For movable Actors, keep location,rotation,scale. */
	UPROPERTY(BlueprintReadWrite)
	FTransform Transform;

	/* For inventorable Actors, stores info about how many items */
	UPROPERTY(BlueprintReadWrite)
	FInventorableComponentSaveload InventorableComponentSaveload;

	/* For inventory Actors, stores info about it's inventory */
	UPROPERTY(BlueprintReadWrite)
	FInventoryComponentSaveload InventoryComponentSaveload;

	FSaveloadActorStructure();

	FSaveloadActorStructure(FName ActorIdentifier, FTransform Transform);

	virtual ~FSaveloadActorStructure();
};
