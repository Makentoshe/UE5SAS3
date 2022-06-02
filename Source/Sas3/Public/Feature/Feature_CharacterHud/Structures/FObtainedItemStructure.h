// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FObtainedItemStructure.generated.h"

/**
 * Structure contains parameters for displaying in the obtaine system
 */
USTRUCT(BlueprintType)
struct SAS3_API FObtainedItemStructure
{
	GENERATED_BODY()

	// Contains the item name that will be displayed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Title;

	// Contains obtained items count
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count;

	// Should items count be displayed 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShowCount;

	// Default constructor
	FObtainedItemStructure();

	// Default virtual destructor
	virtual ~FObtainedItemStructure();

	// Allows to assign an object using = operator.
	// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
	FObtainedItemStructure& operator=(const FObtainedItemStructure Structure);

};
