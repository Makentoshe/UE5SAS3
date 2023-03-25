// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FSDisplayLabel.generated.h"

/**
 * Contains only main info about object which info will be displayed. 
 * 
 * It can be road sign, character name, etc
 */
USTRUCT(BlueprintType)
struct UE5SAS3_API FSDisplayLabel : public FTableRowBase
{
	GENERATED_BODY()

	// Contains the item name that will be displayed to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Label;

	// Default constructor
	FSDisplayLabel();

	// Default destructor
	// Note: virtual for the super call
	virtual ~FSDisplayLabel();

	// Allows to assign an object using = operator.
	FSDisplayLabel& operator=(const FSDisplayLabel Structure);
};
