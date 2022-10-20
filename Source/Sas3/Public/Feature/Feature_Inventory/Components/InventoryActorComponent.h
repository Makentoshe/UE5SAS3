// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryItemStructure.h>
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryUiActorComponent.h>
#include <Sas3/Public/Feature/Feature_Inventory/Structures/Wrappers/InventoryItemStructureWrapper.h>
#include "InventoryActorComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddInventoryItemWrapper, UInventoryItemStructureWrapper*, ItemStructureWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryActorOnAddInventoryItem, FInventoryItemStructure, InventoryItem);


/* Component declares that the Actor contains Inventory */
UCLASS(BlueprintType)
class SAS3_API UInventoryActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Default constructor
	UInventoryActorComponent();

	//Default virtual destructor
	~UInventoryActorComponent();

	// Add provided item to the inventory
	UFUNCTION(BlueprintCallable)
	void AddInventoryItem(FInventoryItemStructure InventoryItem);

	UFUNCTION(BlueprintCallable)
	void ClearInventoryItems();

	UFUNCTION(BlueprintCallable)
	void SetInventoryItems(TArray<FInventoryItemStructure> InventoryItems);

	// Returns all items currently placed in the inventory
	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FInventoryItemStructure> GetInventoryItems();

private:
	// Add provided item to the inventory starting from the new stack
	UFUNCTION()
	void AddInventoryItemNewStack(FInventoryItemStructure InventoryItem);

public:
	// Defines how many stacks of items might be in the inventory
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory Settings")
	int32 InventorySize;

protected:

	// Contains all items in the inventory
	UPROPERTY(BlueprintReadOnly)
	TArray<FInventoryItemStructure> InventoryItems;

public:

	// Calls when new inventory item was added to the inventory
	UPROPERTY(BlueprintAssignable)
	FInventoryActorOnAddInventoryItem OnAddInventoryItem;
};
