// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponent/InventoryActorComponent.h"

// Sets default values for this component's properties
UInventoryActorComponent::UInventoryActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// Intialize default inventory settings
	this->InventorySize = 10;
	this->StackSize = 10;
}

// Called when the game starts
void UInventoryActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UInventoryActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Returns all items from the current inventory state
TArray<FInventoryItemStructure> UInventoryActorComponent::GetInventoryItems()
{
	return Inventory;
}

// Add item to the inventory
void UInventoryActorComponent::AddInventoryItem(FInventoryItemStructure InventoryItem) 
{   // First of all check that count is a valid value
	if(InventoryItem.Count < 0) throw std::invalid_argument("Count shouldn't be negative");
	// If item not stackable: just create a new stack for each entry
	if (InventoryItem.IsStacking) AddInventoryItemStackable(InventoryItem); else AddInventoryItemUnstackable(InventoryItem);
}

// Add item to the inventory
void UInventoryActorComponent::AddInventoryItemUnstackable(FInventoryItemStructure InventoryItem)
{   // Just iterate through all items that we have in InventoryItem and put one by one to the Inventory
	for (int i = 0; i < InventoryItem.Count; i++) {
		Inventory.Add(FInventoryItemStructure(InventoryItem, 1));
	}
}

// Add item to the inventory
void UInventoryActorComponent::AddInventoryItemStackable(FInventoryItemStructure InventoryItem)
{   // Try to find item in the Inventory
	if (Inventory.IsEmpty()) AddInventoryItemNewStack(InventoryItem); else AddInventoryItemAppend(InventoryItem);
}

// Add item to the inventory starting from the new stack
void UInventoryActorComponent::AddInventoryItemNewStack(FInventoryItemStructure InventoryItem) 
{   // If Items more than the one stack can have - add full stack and repeat call else just add
	if (InventoryItem.Count > StackSize) {
		Inventory.Add(FInventoryItemStructure(InventoryItem, StackSize));

		auto NewInventoryItem = FInventoryItemStructure(InventoryItem, InventoryItem.Count - StackSize);
		AddInventoryItemNewStack(NewInventoryItem);
	} else {
		Inventory.Add(InventoryItem);
	}
}

// Add item to the inventory firstly trying to append to the existsing stacks
void UInventoryActorComponent::AddInventoryItemAppend(FInventoryItemStructure InventoryItem) 
{	// Go through all inventory items and try to find our item
	for (int i = 0; i < Inventory.Num(); i++) { // Skip item if it is not our type or already have full stacks
	    if (!Inventory[i].Title.IsEqual(InventoryItem.Title, ENameCase::CaseSensitive)) continue;
		if (Inventory[i].Count == StackSize) continue;

		int32 CountSum = Inventory[i].Count + InventoryItem.Count;
		if (CountSum < StackSize) { // Just append and return
			Inventory[i] = FInventoryItemStructure(Inventory[i], CountSum);
			return;
		} else { // Append current item till full stack and then add new stacks
			Inventory[i] = FInventoryItemStructure(Inventory[i], StackSize);
			AddInventoryItemNewStack(FInventoryItemStructure(Inventory[i], CountSum - StackSize));
			return;
		}
	}
	// Will be here only if we didn't find our item type in the inventory, so we just create a new stacks
	AddInventoryItemNewStack(InventoryItem);
}
