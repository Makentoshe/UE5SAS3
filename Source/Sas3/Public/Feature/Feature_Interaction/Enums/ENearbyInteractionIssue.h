// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ENearbyInteractionIssue: uint8 {
	RemoveCantRemoveWrapperFromList		UMETA(DisplayName = "Remove: Can't remove wrapper from the list"),
	InteractionEmptyInteractionsList    UMETA(DisplayName = "Interaction: Interactions list empty"),
	InteractionSelectionIssue			UMETA(DisplayName = "Interaction: Invalid selection and list size"),
	InteractionTypeIsNone				UMETA(DisplayName = "Interaction: Action type is None"),
	InteractionInventoryItemActorCast	UMETA(DisplayName = "Interaction: Can't cast to InventoryItemActor"),
	InteractionEnvironmentItemActorCast	UMETA(DisplayName = "Interaction: Can't cast to EnvironmentItemActor"),
};
