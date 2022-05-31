// Fill out your copyright notice in the Description page of Project Settings.

#include "Feature/Feature_Interaction/Components/InteractorActorComponent.h"
#include "Feature/Feature_Inventory/Interfaces/InventoryActorComponentHolder.h"
#include "Feature/Feature_Interaction/Interfaces/InteractorUiActorComponentHolder.h"

// Sets default values for this component's properties
UInteractorActorComponent::UInteractorActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}

UInteractorActorComponent::~UInteractorActorComponent()
{
}

void UInteractorActorComponent::AddNearbyInteractionWrapper(UNearbyInteractionWrapper* Wrapper)
{   // Add wrapper to the list and notify about it
	this->NearbyInteractions.Add(Wrapper);
	this->OnAddNearbyInteraction3.Broadcast(Wrapper);
}

void UInteractorActorComponent::AddNearbyInteractionStructure(UPARAM(ref)const FNearbyInteractionStructure& Structure)
{   // Create wrapper and call AddNearbyInteractionWrapper
	UNearbyInteractionWrapper* Wrapper = NewObject<UNearbyInteractionWrapper>();
	Wrapper->NearbyInteractionStructure = Structure;
	AddNearbyInteractionWrapper(Wrapper);
}

