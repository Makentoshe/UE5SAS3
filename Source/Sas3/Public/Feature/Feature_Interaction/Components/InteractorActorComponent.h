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
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNearbyInteraction);


UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UInteractorActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractorActorComponent();

protected:
	
	// Called when a component is registered, after Scene is set, but before CreateRenderState_Concurrent or OnCreatePhysicsState are called.
	virtual void OnRegister() override;

	// Called when a component is unregistered. Called after DestroyRenderState_Concurrent and OnDestroyPhysicsState are called.
	virtual void OnUnregister() override;

public:

	// Index of selected element in the interaction list
	UPROPERTY(BlueprintReadWrite)
	int32 SelectedInteractionIndex;

	// List of all available nearby interactions
	UPROPERTY(BlueprintReadWrite)
	TArray<UNearbyInteractionWrapper*> NearbyInteractions;

	// Required if interaction with this item requires inventory (pick upping inventory item)
	UPROPERTY(BlueprintReadWrite, Category = Components)
	TObjectPtr<UInventoryActorComponent> InventoryActorComponent;

	// UI of the current component
	UPROPERTY(BlueprintReadWrite, Category = Components)
	TObjectPtr<UInteractorUiActorComponent> InteractorUiActorComponent;

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
};
