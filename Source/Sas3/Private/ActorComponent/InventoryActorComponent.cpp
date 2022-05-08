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
}

// Returns all items from the current inventory state
TArray<FInventoryItemStructure> UInventoryActorComponent::GetInventoryItems()
{
	return Inventory;
}

// Add item to the inventory
void UInventoryActorComponent::AddInventoryItem(FInventoryItemStructure InventoryItem) 
{   // First of all check that count is a valid value
	if(InventoryItem.Count < 1) throw std::invalid_argument("Count shouldn't be negative or zero");
	if (InventoryItem.StackSize < 1) throw std::invalid_argument("StackSize shouldn't be negative or zero");

	// Go through all inventory items and try to find our item
	for (int i = 0; i < Inventory.Num(); i++) { // Skip item if it is not our type or already have full stacks
		if (!Inventory[i].Item.Title.IsEqual(InventoryItem.Item.Title, ENameCase::CaseSensitive)) continue;
		if (Inventory[i].Count == InventoryItem.StackSize) continue;

		int32 CountSum = Inventory[i].Count + InventoryItem.Count;
		if (CountSum < InventoryItem.StackSize) { // Just append and return
			Inventory[i] = FInventoryItemStructure(Inventory[i], CountSum);
			return;
		}
		else { // Append current item till full stack and then add new stacks
			Inventory[i] = FInventoryItemStructure(Inventory[i], InventoryItem.StackSize);
			AddInventoryItemNewStack(FInventoryItemStructure(Inventory[i], CountSum - InventoryItem.StackSize));
			return;
		}
	}
	// Will be here only if we didn't find our item type in the inventory, so we just create a new stacks
	AddInventoryItemNewStack(InventoryItem);
}

// Add item to the inventory starting from the new stack
void UInventoryActorComponent::AddInventoryItemNewStack(FInventoryItemStructure InventoryItem) 
{   // If Items more than the one stack can have - add full stack and repeat call else just add
	if (InventoryItem.Count > InventoryItem.StackSize) {
		Inventory.Add(FInventoryItemStructure(InventoryItem, InventoryItem.StackSize));

		auto NewInventoryItem = FInventoryItemStructure(InventoryItem, InventoryItem.Count - InventoryItem.StackSize);
		AddInventoryItemNewStack(NewInventoryItem);
	} else {
		Inventory.Add(InventoryItem);
	}
}
