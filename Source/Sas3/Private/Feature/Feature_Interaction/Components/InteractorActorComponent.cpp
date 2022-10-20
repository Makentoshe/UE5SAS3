// Fill out your copyright notice in the Description page of Project Settings.

#include "Feature/Feature_Interaction/Components/InteractorActorComponent.h"

// Sets default values for this component's properties
UInteractorActorComponent::UInteractorActorComponent()
{   // Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;

	this->SelectedInteractionIndex = -1;
}

UInteractorActorComponent::~UInteractorActorComponent()
{
}

void UInteractorActorComponent::AddInteractionWrapper(UInteractionWrapper* Wrapper)
{   // Add wrapper to the list
	this->Interactions.Add(Wrapper);

	// Notify that new interaction added to the list
	this->OnAddNearbyInteraction3.Broadcast(Wrapper);

	// Change selection index and select added wrapper
	if (this->Interactions.Num() == 1) SwapInteractionSelectionByIndex(0);	
}

void UInteractorActorComponent::RemoveInteractionWrapper(UInteractionWrapper* Wrapper)
{   // Remove wrapper from the list using operator== to equal elements
	if (!this->Interactions.Remove(Wrapper)) {
		return;
	}
	//Notify about removement
    this->OnRemoveNearbyInteraction3.Broadcast(Wrapper);
	// Deselect removed wrapper
	Wrapper->InteractableComponent->SelectInteractableOwner(GetOwner(), false);

	if (this->Interactions.Num() == 0) return;

	// If selected index becomes invalid - fix it
	if (this->Interactions.Num() <= this->SelectedInteractionIndex) {
		SwapInteractionSelectionByIndex(this->Interactions.Num() - 1);
	}

	// Select new wrapper on the index if possible
	this->Interactions[this->SelectedInteractionIndex]->InteractableComponent->SelectInteractableOwner(GetOwner(), true);
}

void UInteractorActorComponent::SelectNextNearbyInteractionIndex()
{   // If there aren't any available interactions - just ignore method invokation
	if (this->Interactions.Num() == 0) return;

	// if current index < last index - select next interactable in the list
	if (this->SelectedInteractionIndex < this->Interactions.Num() - 1) {
		SwapInteractionSelectionByIndex(this->SelectedInteractionIndex + 1);
	} else { // or move to the start of the list
		SwapInteractionSelectionByIndex(0);
	}
}

void UInteractorActorComponent::SelectPrevNearbyInteractionIndex()
{   // If there aren't any available interactions - just ignore method invokation
	if (this->Interactions.Num() == 0) return;

	// if current index < 0(index of the first element) - move to the end of the list
	if (this->SelectedInteractionIndex <= 0) { // max to avoid negative index
		SwapInteractionSelectionByIndex(FMath::Max(this->Interactions.Num() - 1, 0));
	} else { // or select previous interactable in the list
		SwapInteractionSelectionByIndex(this->SelectedInteractionIndex - 1);
	}
}

void UInteractorActorComponent::SwapInteractionSelectionByIndex(int32 NewIndex)
{
	int32 OldIndex = this->SelectedInteractionIndex;

	this->SelectedInteractionIndex = NewIndex;
	// Notify about selection change and  provide pointer to the new selected wrapper and its index
	this->OnChangeSelectedInteractionIndex.Broadcast(NewIndex, OldIndex);

	// Deselect old wrapper if possible
	if (this->Interactions.IsValidIndex(OldIndex)) {
		this->Interactions[OldIndex]->InteractableComponent->SelectInteractableOwner(GetOwner(), false);
	}
	// Select new wrapper if possible
	if (this->Interactions.IsValidIndex(NewIndex)) {
		this->Interactions[NewIndex]->InteractableComponent->SelectInteractableOwner(GetOwner(), true);
	}
}

void UInteractorActorComponent::ExecuteSelectedInteractionAction(AActor* InteractedActor)
{   // Check NearbyIteractions list is not empty
	if (this->Interactions.Num() == 0) {
		return; // if interactions list empty
	}
	// Check SelectedInteractionItem is valid
	if (this->Interactions.Num() <= SelectedInteractionIndex) {
		return; // if selection index is higher than interactions count
	}

	// Get selected NearbyInteraction
	auto Wrapper = this->Interactions[this->SelectedInteractionIndex];
	// Call event that actor was interacted
	this->OnInteractionStarted.Broadcast(Wrapper);
}
