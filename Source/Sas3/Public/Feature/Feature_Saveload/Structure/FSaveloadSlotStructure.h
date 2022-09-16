// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSaveloadSlotStructure.generated.h"

/**
 * Structure contains parameters for working with save game files.
 */
USTRUCT(BlueprintType)
struct SAS3_API FSaveloadSlotStructure
{

	GENERATED_BODY()

public:

	// Name of the current saveload file (save game instance)
	UPROPERTY(BlueprintReadOnly)
	FString Filename;

	// Is this saveload initialized
	UPROPERTY(BlueprintReadOnly)
	bool IsInitialized;

	FSaveloadSlotStructure();
	FSaveloadSlotStructure(FString Filename);

	virtual ~FSaveloadSlotStructure();

};
