// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FSSaveloadObject.generated.h"

/**
 * Object contains all available data for an actor
 */
USTRUCT(BlueprintType, Category = "Saveload Feature")
struct UE5SAS3_API FSSaveloadObject
{
	GENERATED_BODY()

public:

	// Contains actor transform state
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Saveload Feature")
	FTransform ActorTransform;


	// Default constructor
	FSSaveloadObject();

	// Default destructor
	// Note: virtual for the super call
	virtual ~FSSaveloadObject();

	// Allows to assign an object using = operator.
	FSSaveloadObject& operator=(const FSSaveloadObject Structure);
};
