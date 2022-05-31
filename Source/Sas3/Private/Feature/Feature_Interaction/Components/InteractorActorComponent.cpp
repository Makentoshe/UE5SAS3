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

void UInteractorActorComponent::RemoveNearbyInteractionWrapper(UNearbyInteractionWrapper* Wrapper)
{   // return provided Wrapper from the list
	if (this->NearbyInteractions.Remove(Wrapper) <= 0) {
		// If we don't remove wrapper - notify about it
		auto text = TEXT("UInteractorActorComponent: Cant remove UNearbyInteractionWrapper from the list");
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, text);
		return;
	}
	// Fix selection
	this->SelectedInteractionIndex = FMath::Max(FMath::Min(this->SelectedInteractionIndex, this->NearbyInteractions.Num() - 1), 0);	
	// Notify about removement
	this->OnRemoveNearbyInteraction3.Broadcast(Wrapper);
}

void UInteractorActorComponent::RemoveNearbyInteractionStructure(UPARAM(ref) const FNearbyInteractionStructure& Structure)
{	// Trying to find wrapper with the same structure
	for (UNearbyInteractionWrapper* Wrapper : this->NearbyInteractions) {
		if (Wrapper->NearbyInteractionStructure != Structure) continue;
		// If we find our wrapper - call to remove it and return from the function
		RemoveNearbyInteractionWrapper(Wrapper);
		return;
	}
	// If we don't find wrapper - notify about it
	auto text = TEXT("UInteractorActorComponent: Cant find UNearbyInteractionWrapper for provided FNearbyInteractionStructure");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, text);
}

void UInteractorActorComponent::SelectNextNearbyInteractionIndex()
{   // if current index < last index
	if (this->SelectedInteractionIndex < this->NearbyInteractions.Num() - 1) {
		this->SelectedInteractionIndex = this->SelectedInteractionIndex + 1;
	}
	else {
		this->SelectedInteractionIndex = 0;
	}
	// Notify about selection change and provide pointer to the new selected wrapper and its index
	this->OnChangeSelectedInteractionIndex.Broadcast(this->SelectedInteractionIndex, this->NearbyInteractions[SelectedInteractionIndex]);
}

void UInteractorActorComponent::SelectPrevNearbyInteractionIndex()
{
	if (this->SelectedInteractionIndex <= 0) {
		this->SelectedInteractionIndex = FMath::Max(NearbyInteractions.Num() - 1, 0);
	}
	else {
		this->SelectedInteractionIndex = this->SelectedInteractionIndex - 1;
	}
	// Notify about selection change and provide pointer to the new selected wrapper and its index
	this->OnChangeSelectedInteractionIndex.Broadcast(this->SelectedInteractionIndex, this->NearbyInteractions[SelectedInteractionIndex]);
}

void UInteractorActorComponent::SelectNearbyInteractionIndex(int32 NewIndex)
{
	this->SelectedInteractionIndex = NewIndex;
	// Notify about selection change and provide pointer to the new selected wrapper and its index
	this->OnChangeSelectedInteractionIndex.Broadcast(this->SelectedInteractionIndex, this->NearbyInteractions[SelectedInteractionIndex]);
}

