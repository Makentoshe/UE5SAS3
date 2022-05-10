// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Sas3/Public/Enum/ENearbyActionType.h>
#include <Sas3/Public/Structure/FInventoryItemStructure.h>
#include <Sas3/Public/Structure/FEnvironmentItemStructure.h>
#include "FNearbyActionStructure.generated.h"

/**
 * Describes a nearby action that character can perform.
 */
USTRUCT(BlueprintType)
struct SAS3_API FNearbyActionStructure
{  
	GENERATED_BODY()

	// Contains action title that will be displayed at the main text view
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ActionTitle;

	// Contains additional description to the action
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ActionDescription;

	// Action icon
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlateBrush ActionIcon;

	// Defines which action type should be performed on trigger
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ENearbyActionType ActionType;

	// Should be defined if ActionType set as Inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInventoryItemStructure InventoryItem;

	// Should be defined if ActionType set as Environment
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FEnvironmentItemStructure EnvironmentItem;

	// Should contain a reference to the acted actor
	// Should be defined as InventoryItemActor if ActionType set as Inventory
	// Should be defined as EnvironmentItemActor if ActionType set as Environment
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AActor> NearbyActionActor;

	// Default constructor
	FNearbyActionStructure();
};
