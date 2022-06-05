// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Inventory/Components/InventorableActorComponent.h"
#include "Feature/Feature_Inventory/Interfaces/InventoryActorComponentHolder.h"
#include "Feature/Feature_GameItem/Interfaces/GameItemActorComponentHolder.h"

// Sets default values for this component's properties
UInventorableActorComponent::UInventorableActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}

UInventorableActorComponent::~UInventorableActorComponent()
{
}

void UInventorableActorComponent::ExecuteInventoryItemAction(AActor* InventoryActor)
{   // Check if owner is game item
	if (!this->GetOwner()->GetClass()->ImplementsInterface(UGameItemActorComponentHolder::StaticClass())) {
		return; // return if not
	}
	auto GameItemActorComponent = IGameItemActorComponentHolder::Execute_GetGameItemActorComponent(this->GetOwner());
	if (!IsValid(GameItemActorComponent)) return; // interface doesn't provide any value
	
	// Check if actor is inventory
	if (!InventoryActor->GetClass()->ImplementsInterface(UInventoryActorComponentHolder::StaticClass())) {
		return; // return if not
	}
	auto InventoryActorComponent = IInventoryActorComponentHolder::Execute_GetInventoryActorComponent(InventoryActor);
	if (!IsValid(InventoryActorComponent)) return; // interface doesn't provide any value
	// Create inventory item and add to the inventory
	auto InventoryItemWrapper = GetInventoryItemWrapper(GameItemActorComponent->GameItem3.Title);
	InventoryActorComponent->AddInventoryItemWrapper(InventoryItemWrapper);
	// Notify that item was added to the inventory
	this->OnInventoryItemAction.Broadcast(InventoryActor, InventoryItemWrapper);
}

UInventoryItemStructureWrapper* UInventorableActorComponent::GetInventoryItemWrapper(FName Title)
{   // Create new instance
	auto InventoryItemWrapper = NewObject<UInventoryItemStructureWrapper>();
	// Initialize
	InventoryItemWrapper->InventoryItemStructure.Count = this->InventoryMeta.ItemCount;
	InventoryItemWrapper->InventoryItemStructure.StackSize = this->InventoryMeta.StackSize;
	InventoryItemWrapper->InventoryItemStructure.Title = Title;

	return InventoryItemWrapper;
}

