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

	/* Contains all 'SaveGame' marked variables of the Actor */
	UPROPERTY(BlueprintReadWrite)
	TArray<uint8> ByteData;

	FSaveloadActorStructure();

	FSaveloadActorStructure(FName ActorIdentifier, FTransform Transform, TArray<uint8> ByteData);

	virtual ~FSaveloadActorStructure();
};
