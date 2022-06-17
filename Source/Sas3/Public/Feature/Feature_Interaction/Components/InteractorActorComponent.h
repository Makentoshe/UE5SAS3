// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Feature/Feature_Interaction/Enums/ENearbyInteractionIssue.h>
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryActorComponent.h>
#include <Sas3/Public/Feature/Feature_Interaction/Structure/Wrapper/InteractionWrapper.h>
#include "InteractorActorComponent.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorInteracted, AActor*, InteractedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractorComponentInteractionFinished, AActor*, InteractedActor, UInteractionWrapper*, InteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddNearbyInteraction3, UInteractionWrapper*, InteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveNearbyInteraction3, UInteractionWrapper*, InteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChangeSelectedInteractionIndex, int32, NewIndex, int32, OldIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractorComponentIssue, ENearbyInteractionIssue, Reason);


/* Any Actor that can interact with other actors should contain this component */
UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UInteractorActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractorActorComponent();
	// Default virtual destructor
	virtual ~UInteractorActorComponent();

	// Add provided Wrapper to the interactions list
	UFUNCTION(BlueprintCallable, Category="Interactions | Manipulation")
	void AddInteractionWrapper(UInteractionWrapper* Wrapper);

	// Removes provided Wrapper from the nearby interactions list
	UFUNCTION(BlueprintCallable, Category = "Interactions | Manipulation")
	void RemoveInteractionWrapper(UInteractionWrapper* Wrapper);

	// Moves SelectedInteractionIndex to the next value or resets it to the start
	UFUNCTION(BlueprintCallable, Category = "Interactions | Selection")
	void SelectNextNearbyInteractionIndex();

	// Moves SelectedInteractionIndex to the next value or resets it to the start
	UFUNCTION(BlueprintCallable, Category = "Interactions | Selection")
	void SelectPrevNearbyInteractionIndex();

	// Moves SelectedInteractionIndex to the exactly provided value
	UFUNCTION(BlueprintCallable, Category = "Interactions | Selection")
	void SelectNearbyInteractionIndex(int32 NewIndex);

	// Executes selected NearbyInteraction
	UFUNCTION(BlueprintCallable, Category = "Interactions | Action")
	void ExecuteSelectedInteractionAction(AActor* InteractedActor);

private:

	// Executes selected NearbyInteraction after checks
	UFUNCTION(Category = "Interactions | Action")
	void ExecuteSelectedInteractionActionInternal(AActor* InteractedActor, UInteractionWrapper* Wrapper);

	// Invokes InteractableActor's callback with the new SelectionValue if possible
	// (if InteractableActor contains Interactable component)
	UFUNCTION(Category = "Interactions | Selection")
	void ChangeInteractableActorSelection(AActor* InteractableActor, bool SelectionValue);

public:

	// Index of selected element in the interaction list
	UPROPERTY(BlueprintReadOnly)
	int32 SelectedInteractionIndex;

	// List of available interactions
	UPROPERTY(BlueprintReadOnly)
	TArray<UInteractionWrapper*> Interactions;

	// Calls when game item was interacted. No matter which item was interacted this event will be called
	UPROPERTY(BlueprintAssignable, Category = "Interactor Delegates | Action")
	FOnActorInteracted OnActorInteracted;

	// Called when interaction was finished and component can finalize its interaction 
	UPROPERTY(BlueprintAssignable, Category = "Interactor Delegates | Action")
	FInteractorComponentInteractionFinished OnInteractionFinished;

	// Calls when new interaction was be added to the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates | Manipulation")
	FOnAddNearbyInteraction3 OnAddNearbyInteraction3;

	// Calls when interaction was removed to the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates | Manipulation")
	FOnRemoveNearbyInteraction3 OnRemoveNearbyInteraction3;
	
	// Calls when selected interaction index was changed
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates | Selection")
	FOnChangeSelectedInteractionIndex OnChangeSelectedInteractionIndex;

	// Calls when any issue occurs
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates | Errors")
	FInteractorComponentIssue OnNearbyInteractionIssue;
};
