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
TArray<UInventoryItemStructureWrapper*> UInventoryActorComponent::GetInventoryItems() { return InventoryItems; }

UInventoryItemStructureWrapper* UInventoryActorComponent::BuildInventoryItemStructureWrapper(FInventoryItemStructure& Structure)
{   // Create object
	UInventoryItemStructureWrapper* Wrapper = NewObject<UInventoryItemStructureWrapper>();
	// Initialize object
	Wrapper->InventoryItemStructure = Structure;
	// Return pointer
	return Wrapper;
}

void UInventoryActorComponent::AddInventoryItemWrapper(UInventoryItemStructureWrapper* Wrapper) 
{
	if (Wrapper->InventoryItemStructure.Count < 1) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Error: Count shouldn't be negative or zero"));
		return;
	}
	// Check that StackSize in a valid value
	if (Wrapper->InventoryItemStructure.StackSize < 1) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Error: StackSize shouldn't be negative or zero"));
		return;
	}

	this->OnAddInventoryItemWrapper.Broadcast(Wrapper);
	
	// Go through all inventory items and try to find our item
	for (int i = 0; i < InventoryItems.Num(); i++) {
		auto CurrentWrapper = InventoryItems[i];
		// Skip item if it is not our type or already have full stacks
		if (!InventoryItems[i]->InventoryItemStructure.Title.IsEqual(Wrapper->InventoryItemStructure.Title, ENameCase::CaseSensitive)) {
			continue;
		}
		if (InventoryItems[i]->InventoryItemStructure.Count == Wrapper->InventoryItemStructure.StackSize) {
			continue;
		}

		int32 CountSum = InventoryItems[i]->InventoryItemStructure.Count + Wrapper->InventoryItemStructure.Count;
		if (CountSum <= Wrapper->InventoryItemStructure.StackSize) { // Just append and return  
			InventoryItems[i]->InventoryItemStructure = FInventoryItemStructure(InventoryItems[i]->InventoryItemStructure, CountSum);
			return;
		}
		else { // Append current item till full stack and then add new stacks
			InventoryItems[i]->InventoryItemStructure = FInventoryItemStructure(InventoryItems[i]->InventoryItemStructure, Wrapper->InventoryItemStructure.StackSize);
			auto NewStructure = FInventoryItemStructure(InventoryItems[i]->InventoryItemStructure, CountSum - Wrapper->InventoryItemStructure.StackSize);
			auto NewWrapper = BuildInventoryItemStructureWrapper(NewStructure);
			AddInventoryItemNewStackWrapper(NewWrapper);
			return;
		}
	}

	// Will be here only if we didn't find our item type in the inventory, so we just create a new stacks
	AddInventoryItemNewStackWrapper(Wrapper);
}

// Add provided item to the inventory starting from the new stack
void UInventoryActorComponent::AddInventoryItemNewStackWrapper(UInventoryItemStructureWrapper* Wrapper)
{   // If Items more than the one stack can have - add full stack and repeat call else just add
	if (Wrapper->InventoryItemStructure.Count > Wrapper->InventoryItemStructure.StackSize) {
		auto NewFullStackedStructure = FInventoryItemStructure(Wrapper->InventoryItemStructure, Wrapper->InventoryItemStructure.StackSize);
		auto NewFullStackedWrapper = BuildInventoryItemStructureWrapper(NewFullStackedStructure);
		InventoryItems.Add(NewFullStackedWrapper);

		auto NextNewStackCount = Wrapper->InventoryItemStructure.Count - Wrapper->InventoryItemStructure.StackSize;
		auto NextNewStructure = FInventoryItemStructure(Wrapper->InventoryItemStructure, NextNewStackCount);
		auto NextNewWrapper = BuildInventoryItemStructureWrapper(NextNewStructure);
		AddInventoryItemNewStackWrapper(NextNewWrapper);
	}
	else {
		InventoryItems.Add(Wrapper);
	}
}
