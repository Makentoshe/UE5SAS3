// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FEnvironmentMetaStructure.generated.h"

/**
 * Meta structure works with GameItemStructure that allows
 * to understand environment preferences for this item.
 */
USTRUCT(BlueprintType)
struct SAS3_API FEnvironmentMetaStructure
{
	GENERATED_BODY()

	// Contains additional interaction description for this item that player will see
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Description;

	// Is player able to interact with this item right now
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsEnabled;

	// Default constructor
	FEnvironmentMetaStructure();

	// Note: virtual for the super call
	virtual ~FEnvironmentMetaStructure();

	// Allows to assign an object using = operator.
	// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
	FEnvironmentMetaStructure& operator=(const FEnvironmentMetaStructure Structure);
};
