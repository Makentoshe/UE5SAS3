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

void UInventoryActorComponent::OnRegister()
{
	Super::OnRegister();

	// Setup InventoryActorComponent variable
	if (GetOwner()->GetClass()->ImplementsInterface(UInventoryUiActorComponentHolder::StaticClass())) {
		this->InventoryUiActorComponent = IInventoryUiActorComponentHolder::Execute_GetInventoryUiActorComponent(GetOwner());
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Error: Owner doesn't contents InventoryUiActorComponent"));
	}
}

void UInventoryActorComponent::OnUnregister()
{
	Super::OnUnregister();

	this->InventoryUiActorComponent = nullptr;
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


// Add item to the inventory
void UInventoryActorComponent::AddInventoryItem(FInventoryItemStructure InventoryItemStructure) 
{   // Check that count is a valid value
	if (InventoryItemStructure.Count < 1) { 
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Error: Count shouldn't be negative or zero"));
		return;
	}
	// Check that StackSize in a valid value
	if (InventoryItemStructure.StackSize < 1) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Error: StackSize shouldn't be negative or zero"));
		return;
	}

	// Go through all inventory items and try to find our item
	for (int i = 0; i < InventoryItems.Num(); i++) { 
		auto CurrentStructure = InventoryItems[i]->InventoryItemStructure;
		// Skip item if it is not our type or already have full stacks
		if (!CurrentStructure.Title.IsEqual(InventoryItemStructure.Title, ENameCase::CaseSensitive)) {
			continue;
		}
		if (CurrentStructure.Count == InventoryItemStructure.StackSize) {
			continue;
		}

		int32 CountSum = CurrentStructure.Count + InventoryItemStructure.Count;
		if (CountSum < InventoryItemStructure.StackSize) { // Just append and return
			auto NewStructure = FInventoryItemStructure(CurrentStructure, CountSum);
			InventoryItems[i] = BuildInventoryItemStructureWrapper(NewStructure);
			return;
		}
		else { // Append current item till full stack and then add new stacks
			auto Structure = FInventoryItemStructure(CurrentStructure, InventoryItemStructure.StackSize);
			InventoryItems[i] = BuildInventoryItemStructureWrapper(Structure);
			AddInventoryItemNewStack(FInventoryItemStructure(CurrentStructure, CountSum - InventoryItemStructure.StackSize));
			return;
		}
	}
	// Will be here only if we didn't find our item type in the inventory, so we just create a new stacks
	AddInventoryItemNewStack(InventoryItemStructure);
}

// Add provided item to the inventory starting from the new stack
void UInventoryActorComponent::AddInventoryItemNewStack(FInventoryItemStructure InventoryItemStructure) 
{   // If Items more than the one stack can have - add full stack and repeat call else just add
	if (InventoryItemStructure.Count > InventoryItemStructure.StackSize) {
		auto Structure = FInventoryItemStructure(InventoryItemStructure, InventoryItemStructure.StackSize);
		InventoryItems.Add(BuildInventoryItemStructureWrapper(Structure));

		auto NewInventoryItem = FInventoryItemStructure(InventoryItemStructure, InventoryItemStructure.Count - InventoryItemStructure.StackSize);
		AddInventoryItemNewStack(NewInventoryItem);
	} 
	else {
		InventoryItems.Add(BuildInventoryItemStructureWrapper(InventoryItemStructure));
	}
}
