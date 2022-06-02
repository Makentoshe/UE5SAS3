// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <Sas3/Public/Feature/Feature_CharacterHud/Structures/FObtainedItemStructure.h>
#include "ObtainedItemWrapper.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SAS3_API UObtainedItemWrapper : public UObject
{
	GENERATED_BODY()

public:
	// Default constructor
	UObtainedItemWrapper();

	// Constructor with value
	UObtainedItemWrapper(FObtainedItemStructure& Structure);

	// Default virtual destructor
	virtual ~UObtainedItemWrapper();

	// Returns a copied NearbyInteractionStructure
	UFUNCTION(BlueprintCallable)
	FObtainedItemStructure GetObtainedItemStructure();

public:

	// Wrapped structure
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FObtainedItemStructure ObtainedItemStructure;

};
