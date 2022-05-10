// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Sas3/Public/Structure/FGameItemStructure.h>
#include "FEnvironmentItemStructure.generated.h"

/**
 * Structure contains valuable parameters for game environment
 */
USTRUCT(BlueprintType)
struct SAS3_API FEnvironmentItemStructure
{
	GENERATED_BODY()

	// Contains the base item 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameItemStructure Item;

	FEnvironmentItemStructure();

	~FEnvironmentItemStructure();
};
