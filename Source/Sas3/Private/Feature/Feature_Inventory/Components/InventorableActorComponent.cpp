// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Inventory/Components/InventorableActorComponent.h"

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
{
	this->OnInventoryItemAction.Broadcast(InventoryActor);
}

