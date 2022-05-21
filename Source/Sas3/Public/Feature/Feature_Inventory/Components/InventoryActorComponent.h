// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryItemStructure.h>
#include <Sas3/Public/Items/Inventory/Actors/InventoryItemActor.h>
#include "InventoryActorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddPickupableInventoryItem, FInventoryItemStructure, InventoryItem, AInventoryItemActor*, InventoryItemActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRemovePickupableInventoryItem, FInventoryItemStructure, InventoryItem, AInventoryItemActor*, InventoryItemActor);

/* Component declares that the Actor contains Inventory */
UCLASS(BlueprintType)
class SAS3_API UInventoryActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryActorComponent();

protected:
	// Called when a component is registered, after Scene is set, but before CreateRenderState_Concurrent or OnCreatePhysicsState are called.
	virtual void OnRegister() override;

	// Called when a component is unregistered. Called after DestroyRenderState_Concurrent and OnDestroyPhysicsState are called.
	virtual void OnUnregister() override;

public: 
	// Defines how many stacks of items might be in the inventory
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory Settings")
	int32 InventorySize;

private:
	// Contains all items in the inventory
	TArray<FInventoryItemStructure> Inventory;

public:
	// Add provided item to the inventory
	UFUNCTION(BlueprintCallable)
	void AddInventoryItem(FInventoryItemStructure InventoryItem);

	// Add provided item to list of available for pickuping
	UFUNCTION(BlueprintCallable)
	void AddPickupableInventoryItem(FInventoryItemStructure InventoryItem, AInventoryItemActor* Actor);
	// Calls when InventoryItem adds to the pickuping list
	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnAddPickupableInventoryItem OnAddPickupableInventoryItem;

	// Remove provided item from list of available for pickuping
	UFUNCTION(BlueprintCallable)
	void RemovePickupableInventoryItem(FInventoryItemStructure InventoryItem, AInventoryItemActor* Actor);
	// Calls when InventoryItem removes from the pickuping list
	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnRemovePickupableInventoryItem OnRemovePickupableInventoryItem;
	
	// Returns all items currently placed in the inventory
	UFUNCTION(BlueprintCallable)
	TArray<FInventoryItemStructure> GetInventoryItems();

private:
	// Add provided item to the inventory starting from the new stack
	void AddInventoryItemNewStack(FInventoryItemStructure InventoryItem);
};
