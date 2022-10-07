// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Inventory/Components/InventorableActorComponent.h"
#include "Feature/Feature_Inventory/Interfaces/InventoryActorComponentHolder.h"
#include "Feature/Features/Interfaces/GameItemActorComponentHolder.h"

// Sets default values for this component's properties
UInventorableActorComponent::UInventorableActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}

UInventorableActorComponent::~UInventorableActorComponent()
{
}

void UInventorableActorComponent::ExecuteInventoryItemAction(UInventoryActorComponent* InventoryComponent)
{   
	this->OnInventoryItemAction.Broadcast(InventoryComponent);
}

UInventoryItemStructureWrapper* UInventorableActorComponent::CreateInventoryItemWrapper(FName Title)
{   // Create new instance
	auto InventoryItemWrapper = NewObject<UInventoryItemStructureWrapper>();
	// Initialize
	InventoryItemWrapper->InventoryItemStructure.Count = this->InventoryMeta.ItemCount;
	InventoryItemWrapper->InventoryItemStructure.StackSize = this->InventoryMeta.StackSize;
	InventoryItemWrapper->InventoryItemStructure.Title = Title;

	return InventoryItemWrapper;
}
