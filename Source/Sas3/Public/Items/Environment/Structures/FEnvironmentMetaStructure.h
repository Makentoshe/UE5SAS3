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

public:
	FEnvironmentMetaStructure();

	// Contains additional interaction description for this item that player will see
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Description;
};
