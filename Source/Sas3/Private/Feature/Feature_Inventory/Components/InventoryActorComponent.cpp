// Fill out your copyright notice in the Description page of Project Settings.


#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryActorComponent.h>
#include "Feature/Feature_Inventory/Interfaces/InventoryUiActorComponentHolder.h"
#include <Runtime/UMG/Public/Blueprint/UserWidget.h>

// Sets default values for this component's properties
UInventoryActorComponent::UInventoryActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;

	// Intialize default inventory settings
	this->InventorySize = 10;
}

UInventoryActorComponent::~UInventoryActorComponent()
{
	// Empties the array.It calls the destructors on held items if needed.
	this->InventoryItems.Empty();
}

// Returns all items in the inventory
TArray<FInventoryItemStructure> UInventoryActorComponent::GetInventoryItems() { 
	return InventoryItems;
}

void UInventoryActorComponent::AddInventoryItem(FInventoryItemStructure InventoryItem) 
{
	// Check that we can take an item
	if (InventoryItem.Count < 1) {
		return; // if not
	}
	// Check that item have a valid stack value
	if (InventoryItem.StackSize < 1) {
		return; //if not
	}

	this->OnAddInventoryItem.Broadcast(InventoryItem);

	// Go through all inventory items and try to find our item
	for (int i = 0; i < InventoryItems.Num(); i++) {
		auto CurrentInventoryItem = InventoryItems[i];
		//auto CurrentWrapper = InventoryItems[i];
		// Skip item if it is not our type or already have full stacks
		if (!InventoryItems[i].Title.IsEqual(InventoryItem.Title, ENameCase::CaseSensitive)) {
			continue;
		}
		// Check current slot is full
		if (InventoryItems[i].Count == InventoryItem.StackSize) {
			continue;
		}

		int32 CountSum = InventoryItems[i].Count + InventoryItem.Count;
		if (CountSum <= InventoryItem.StackSize) { // Just append and return  
			InventoryItems[i] = FInventoryItemStructure(InventoryItems[i], CountSum);
		}
		else { // Append current item till full stack and then add new stacks
			InventoryItems[i] = FInventoryItemStructure(InventoryItems[i], InventoryItem.StackSize);
			auto NewStructure = FInventoryItemStructure(InventoryItems[i], CountSum - InventoryItem.StackSize);
			AddInventoryItemNewStack(NewStructure);
		}

		return;
	}

	// Will be here only if we didn't find our item type in the inventory, so we just create a new stacks
	AddInventoryItemNewStack(InventoryItem);
}

void UInventoryActorComponent::ClearInventoryItems()
{
	this->InventoryItems.Empty();
}

void UInventoryActorComponent::SetInventoryItems(TArray<FInventoryItemStructure> InventoryItemsArray)
{
	this->InventoryItems = InventoryItemsArray;
}

void UInventoryActorComponent::AddInventoryItemNewStack(FInventoryItemStructure InventoryItem)
{
	if (InventoryItem.Count <= InventoryItem.StackSize) {
		InventoryItems.Add(InventoryItem);
	} else {
		auto NewFullStackedInventoryItem = FInventoryItemStructure(InventoryItem, InventoryItem.StackSize);
		InventoryItems.Add(NewFullStackedInventoryItem);

		auto NextNewStackCount = InventoryItem.Count - InventoryItem.StackSize;
		auto NextNewInventoryItem = FInventoryItemStructure(InventoryItem, NextNewStackCount);
		AddInventoryItemNewStack(NextNewInventoryItem);
	}
}
