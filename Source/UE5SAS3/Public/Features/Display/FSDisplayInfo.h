// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FSDisplayInfo.generated.h"

/**
 * Contains object name and short description.
 *
 * It can be any action
 */
USTRUCT(BlueprintType)
struct UE5SAS3_API FSDisplayInfo : public FTableRowBase
{
	GENERATED_BODY()

public:

	// Contains the item name that will be displayed to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Label;

	// Contains the item short description that will be displayed to the player. Please, use around 5-10 words
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	// Default constructor
	FSDisplayInfo();

	// Default destructor
	// Note: virtual for the super call
	virtual ~FSDisplayInfo();

	// Allows to assign an object using = operator.
	FSDisplayInfo& operator=(const FSDisplayInfo Structure);
};
