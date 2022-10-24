// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

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

	/* Serialized data stored in JSON */
	UPROPERTY(BlueprintReadWrite)
	FString SerializedData;

	FSaveloadActorStructure();

	FSaveloadActorStructure(FName ActorIdentifier, FTransform Transform);

	virtual ~FSaveloadActorStructure();
};
