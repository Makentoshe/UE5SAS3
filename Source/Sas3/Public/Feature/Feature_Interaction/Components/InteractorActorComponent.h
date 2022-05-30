// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Feature/Feature_Interaction/Components/InteractorUiActorComponent.h>
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FNearbyInteractionStructure.h>
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryActorComponent.h>
#include "InteractorActorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddNearbyInteraction, FNearbyInteractionStructure, Structure);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveNearbyInteraction, FNearbyInteractionStructure, Structure);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNextSelectedNearbyInteractionIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPrevSelectedNearbyInteractionIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNearbyInteraction, AActor*, InteractedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameItemInteracted2, AGameItemActor*, GameItemActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemInteracted2, AInventoryItemActor*, InventoryItemActor, AActor*, InteractedActor);

UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UInteractorActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractorActorComponent();

public:

	// Index of selected element in the interaction list
	UPROPERTY(BlueprintReadWrite)
	int32 SelectedInteractionIndex;

	// List of all available nearby interactions
	UPROPERTY(BlueprintReadWrite)
	TArray<UNearbyInteractionWrapper*> NearbyInteractions;

	// Calls when new interaction should be added to the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnAddNearbyInteraction OnAddNearbyInteraction;

	// Calls when new interaction should be added to the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnRemoveNearbyInteraction OnRemoveNearbyInteraction;

	// Calls when next item in the interactions list should be selected. The previous item should be deselected.
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnNextSelectedNearbyInteractionIndex OnNextSelectedNearbyInteractionIndex;

	// Calls when previous item in the interactions list should be selected. The next item should be deselected.
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnPrevSelectedNearbyInteractionIndex OnPrevSelectedNearbyInteractionIndex;

	// Calls when previous item in the interactions list should be selected. The next item should be deselected.
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnNearbyInteraction OnNearbyInteraction;

	// Calls when inventory item was interacted. Called only on inventory item.
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnInventoryItemInteracted2 OnInventoryItemInteracted;

	// Calls when game item was interacted. No matter which item was interacted this event will be called
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnGameItemInteracted2 OnGameItemInteracted;
};
