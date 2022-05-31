// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Feature/Feature_Interaction/Components/InteractorUiActorComponent.h>
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FNearbyInteractionStructure.h>
#include <Sas3/Public/Feature/Feature_Interaction/Structure/Wrapper/NearbyInteractionWrapper.h>
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryActorComponent.h>
#include "InteractorActorComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNearbyInteraction, AActor*, InteractedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameItemInteracted2, AGameItemActor*, GameItemActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemInteracted2, AInventoryItemActor*, InventoryItemActor, AActor*, InteractedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddNearbyInteraction3, UNearbyInteractionWrapper*, NearbyInteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveNearbyInteraction3, UNearbyInteractionWrapper*, NearbyInteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChangeSelectedInteractionIndex, int32, NewIndex, UNearbyInteractionWrapper*, NewSelectedWrapper);


UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UInteractorActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractorActorComponent();
	// Default virtual destructor
	virtual ~UInteractorActorComponent();

	// Add provided Wrapper to the nearby interactions list
	UFUNCTION(BlueprintCallable)
	void AddNearbyInteractionWrapper(UNearbyInteractionWrapper* Wrapper);

	// Creates a Wrapper from the Structure and adds it to the nearby interactions list
	UFUNCTION(BlueprintCallable)
	void AddNearbyInteractionStructure(UPARAM(ref) const FNearbyInteractionStructure& Structure);

	// Removes provided Wrapper from the nearby interactions list
	UFUNCTION(BlueprintCallable)
	void RemoveNearbyInteractionWrapper(UNearbyInteractionWrapper* Wrapper);

	// Finds a Wrapper in the interactions list by the Structure and removes it
	UFUNCTION(BlueprintCallable)
	void RemoveNearbyInteractionStructure(UPARAM(ref) const FNearbyInteractionStructure& Structure);

	// Moves SelectedInteractionIndex to the next value or resets it to the start
	UFUNCTION(BlueprintCallable)
	void SelectNextNearbyInteractionIndex();

	// Moves SelectedInteractionIndex to the next value or resets it to the start
	UFUNCTION(BlueprintCallable)
	void SelectPrevNearbyInteractionIndex();

	// Moves SelectedInteractionIndex to the exactly provided value
	UFUNCTION(BlueprintCallable)
	void SelectNearbyInteractionIndex(int32 NewIndex);

public:

	// Index of selected element in the interaction list
	UPROPERTY(BlueprintReadWrite)
	int32 SelectedInteractionIndex;

	// List of all available nearby interactions
	UPROPERTY(BlueprintReadWrite)
	TArray<UNearbyInteractionWrapper*> NearbyInteractions;

	// Calls when previous item in the interactions list should be selected. The next item should be deselected.
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnNearbyInteraction OnNearbyInteraction;

	// Calls when inventory item was interacted. Called only on inventory item.
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnInventoryItemInteracted2 OnInventoryItemInteracted;

	// Calls when game item was interacted. No matter which item was interacted this event will be called
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnGameItemInteracted2 OnGameItemInteracted;

	// Calls when new interaction was be added to the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnAddNearbyInteraction3 OnAddNearbyInteraction3;

	// Calls when interaction was removed to the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnRemoveNearbyInteraction3 OnRemoveNearbyInteraction3;
	
	// Calls when selected interaction index was changed
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnChangeSelectedInteractionIndex OnChangeSelectedInteractionIndex;
};
