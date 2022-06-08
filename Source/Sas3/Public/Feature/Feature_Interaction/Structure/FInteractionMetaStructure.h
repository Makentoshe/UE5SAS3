// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FInteractionMetaStructure.generated.h"


/**
 * Structure contains meta info about interaction for the selected item
 * 
 * This structure works along with the InteractableComponent and allows to define
 * a FInteractionStructure
 */
USTRUCT(BlueprintType)
struct SAS3_API FInteractionMetaStructure : public FTableRowBase 
{
	GENERATED_BODY()

	// Contains the interaction description that will be displayed to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Description;

	// Default constructor
	FInteractionMetaStructure();

	// Default virtual desctuctor
	virtual ~FInteractionMetaStructure();

	// Allows to assign an object using = operator.
	// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
	FInteractionMetaStructure& operator=(const FInteractionMetaStructure Structure);
};
