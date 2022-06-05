// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EInteractableComponentIssues: uint8 {
	InteractionOverlapInterface			UMETA(DisplayName = "Interaction(InteractableComponent): Overlapped actor doesn't implements UInteractorActorComponentHolder interface"),
	InteractionOverlapPointer			UMETA(DisplayName = "Interaction(InteractableComponent): UInteractorActorComponentHolder interface doesn't provides component"),
};
