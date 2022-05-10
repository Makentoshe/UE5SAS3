// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Structure/FInventoryItemStructure.h>
#include "InventoryActorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddPickupableInventoryItem, FInventoryItemStructure, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemovePickupableInventoryItem, FInventoryItemStructure, Item);

UCLASS()
class SAS3_API UInventoryActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public: 
	// Defines how many stacks of items might be in the inventory
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory Settings")
	int32 InventorySize;

private:
	// Contains all items in the inventory
	UPROPERTY()
	TArray<FInventoryItemStructure> Inventory;

	// List of nearby items available to pick up from the ground
	UPROPERTY()
	TArray<FInventoryItemStructure> PickupableItems;

public:
	// Add provided item to the inventory
	UFUNCTION(BlueprintCallable)
	void AddInventoryItem(FInventoryItemStructure InventoryItem);

	// Add provided item to list of available for pick uping
	UFUNCTION(BlueprintCallable)
	void AddPickupableInventoryItem(FInventoryItemStructure InventoryItem);
	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnAddPickupableInventoryItem OnAddPickupableInventoryItem;

	// Remove provided item from list of available for pick uping
	UFUNCTION(BlueprintCallable)
	void RemovePickupableInventoryItem(FInventoryItemStructure InventoryItem);
	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnRemovePickupableInventoryItem OnRemovePickupableInventoryItem;
	
	// Returns all items currently placed in the inventory
	UFUNCTION(BlueprintCallable)
	TArray<FInventoryItemStructure> GetInventoryItems();

private:
	// Add provided item to the inventory starting from the new stack
	void AddInventoryItemNewStack(FInventoryItemStructure InventoryItem);

};
