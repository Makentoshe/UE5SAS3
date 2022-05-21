// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Inventory/Components/InventoryUiActorComponent.h"

void UInventoryUiActorComponent::OnRegister()
{
	Super::OnRegister();
}

void UInventoryUiActorComponent::OnUnregister()
{
	Super::OnUnregister();
}

// Sets default values for this component's properties
UInventoryUiActorComponent::UInventoryUiActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}
