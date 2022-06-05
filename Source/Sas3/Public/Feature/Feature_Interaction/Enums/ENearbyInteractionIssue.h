// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ENearbyInteractionIssue: uint8 {
	InteractionNotInteractableInterface UMETA(DisplayName = "Interaction(InteractorComponent): Interactable actor doesn't implements UInteractableSphereComponentHolder interface"),
	InteractionNotInteractablePointer   UMETA(DisplayName = "Interaction(InteractorComponent): UInteractorActorComponentHolder interface doesn't provides component"),
	InteractionInvalidSelection			UMETA(DisplayName = "Interaction(InteractorComponent): Invalid selection or list size"),
	InteractionEmptyInteractions	    UMETA(DisplayName = "Interaction(InteractorComponent): Interactions list empty"),


	RemoveCantRemoveWrapperFromList		UMETA(DisplayName = "Remove: Can't remove wrapper from the list"),
	InteractionTypeIsNone				UMETA(DisplayName = "Interaction: Action type is None"),
	InteractionInventoryItemActorCast	UMETA(DisplayName = "Interaction: Can't cast to InventoryItemActor"),
	InteractionEnvironmentItemActorCast	UMETA(DisplayName = "Interaction: Can't cast to EnvironmentItemActor"),
};
