// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FNearbyInteractionStructure.h>
#include <Sas3/Public/Feature/Feature_Interaction/Structure/Wrapper/NearbyInteractionWrapper.h>
#include <Sas3/Public/Feature/Feature_Interaction/Enums/ENearbyInteractionIssue.h>
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryActorComponent.h>
#include <Sas3/Public/Items/Environment/Actors/EnvironmentItemActor.h>
#include <Sas3/Public/Feature/Feature_Interaction/Structure/Wrapper/InteractionWrapper.h>
#include "InteractorActorComponent.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorInteracted, AActor*, InteractedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractorComponentInteractionFinished, AActor*, InteractedActor, UInteractionWrapper*, InteractionWrapper);


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemInteracted2, AInventoryItemActor*, InventoryItemActor, AActor*, InteractedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEnvironmentItemInteracted2, AEnvironmentItemActor*, EnvironmentItemActor, AActor*, InteractedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddNearbyInteraction3, UInteractionWrapper*, InteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveNearbyInteraction3, UInteractionWrapper*, InteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChangeSelectedInteractionIndex, int32, NewIndex, UInteractionWrapper*, NewSelectedWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNearbyInteractionIssue, ENearbyInteractionIssue, Reason);


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
	UFUNCTION(BlueprintCallable)
	void ExecuteSelectedInteractionAction(AActor* InteractedActor);

private:

	// Executes selected NearbyInteraction after checks
	UFUNCTION()
	void ExecuteSelectedInteractionActionInternal(AActor* InteractedActor, UInteractionWrapper* Wrapper);

	// Called when interacted actor has None type
	UFUNCTION()
	void NearbyInteractionNone(UNearbyInteractionWrapper* Wrapper, AActor* InteractedActor);

	// Called when interacted actor has Inventory type
	UFUNCTION()
	void NearbyInteractionInventory(UNearbyInteractionWrapper* Wrapper, AActor* InteractedActor);

	// Called when interacted actor has Environment type
	UFUNCTION()
	void NearbyInteractionEnvironment(UNearbyInteractionWrapper* Wrapper, AActor* InteractedActor);

public:

	// Index of selected element in the interaction list
	UPROPERTY(BlueprintReadOnly)
	int32 SelectedInteractionIndex;

	// List of all available nearby interactions
	UPROPERTY(BlueprintReadOnly)
	TArray<UNearbyInteractionWrapper*> NearbyInteractions;

	// List of available interactions
	UPROPERTY(BlueprintReadOnly)
	TArray<UInteractionWrapper*> Interactions;


	// Calls when game item was interacted. No matter which item was interacted this event will be called
	UPROPERTY(BlueprintAssignable, Category = "Interactor Delegates | Interactions")
	FOnActorInteracted OnActorInteracted;

	// Called when interaction was finished and component can finalize its interaction 
	UPROPERTY(BlueprintAssignable, Category = "Interactor Delegates | Interactions")
	FInteractorComponentInteractionFinished OnInteractionFinished;

	// Calls when inventory item was interacted. Called only on inventory item.
	UPROPERTY(BlueprintAssignable, Category = "Interactor Delegates | Interactions")
	FOnInventoryItemInteracted2 OnInventoryItemInteracted;

	// Calls when Environment item was interacted. Called only on environment item.
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates | Interactions")
	FOnEnvironmentItemInteracted2 OnEnvironmentItemInteracted;


	// Calls when new interaction was be added to the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates | States")
	FOnAddNearbyInteraction3 OnAddNearbyInteraction3;

	// Calls when interaction was removed to the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates | States")
	FOnRemoveNearbyInteraction3 OnRemoveNearbyInteraction3;
	
	// Calls when selected interaction index was changed
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates | States")
	FOnChangeSelectedInteractionIndex OnChangeSelectedInteractionIndex;

	// Calls when any issue occurs
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates | Errors")
	FOnNearbyInteractionIssue OnNearbyInteractionIssue;
};
