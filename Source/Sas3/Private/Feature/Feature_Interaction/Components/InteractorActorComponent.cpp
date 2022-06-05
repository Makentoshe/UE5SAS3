// Fill out your copyright notice in the Description page of Project Settings.

#include "Feature/Feature_Interaction/Components/InteractorActorComponent.h"
#include "Feature/Feature_Interaction/Interfaces/InteractableSphereComponentHolder.h"
#include "Feature/Feature_Inventory/Interfaces/InventoryActorComponentHolder.h"
#include "Feature/Feature_Inventory/Interfaces/InventorableActorComponentHolder.h"


// Sets default values for this component's properties
UInteractorActorComponent::UInteractorActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}

UInteractorActorComponent::~UInteractorActorComponent()
{
}

void UInteractorActorComponent::AddInteractionWrapper(UInteractionWrapper* Wrapper)
{   // Add wrapper to the list and notify about it
	this->Interactions.Add(Wrapper);
	this->OnAddNearbyInteraction3.Broadcast(Wrapper);
}

void UInteractorActorComponent::RemoveInteractionWrapper(UInteractionWrapper* Wrapper)
{   // Remove wrapper from the list using operator== to equal elements
	if (this->Interactions.Remove(Wrapper)) { // Notify about removement
        this->OnRemoveNearbyInteraction3.Broadcast(Wrapper);
		return; 
	}
	// If we don't remove wrapper - notify about it
	this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::RemoveCantRemoveWrapperFromList);
	//todo fix issue
}

void UInteractorActorComponent::SelectNextNearbyInteractionIndex()
{   // If there aren't any available interactions - just ignore method invokation
	if (this->Interactions.Num() == 0) return;
	// if current index < last index
	if (this->SelectedInteractionIndex < this->Interactions.Num() - 1) {
		this->SelectedInteractionIndex = this->SelectedInteractionIndex + 1;
	}
	else {
		this->SelectedInteractionIndex = 0;
	}
	// Notify about selection change and provide pointer to the new selected wrapper and its index
	this->OnChangeSelectedInteractionIndex.Broadcast(this->SelectedInteractionIndex, this->Interactions[SelectedInteractionIndex]);
}

void UInteractorActorComponent::SelectPrevNearbyInteractionIndex()
{   // If there aren't any available interactions - just ignore method invokation
	if (this->Interactions.Num() == 0) return;

	if (this->SelectedInteractionIndex <= 0) {
		this->SelectedInteractionIndex = FMath::Max(this->Interactions.Num() - 1, 0);
	}
	else {
		this->SelectedInteractionIndex = this->SelectedInteractionIndex - 1;
	}
	// Notify about selection change and provide pointer to the new selected wrapper and its index
	this->OnChangeSelectedInteractionIndex.Broadcast(this->SelectedInteractionIndex, this->Interactions[SelectedInteractionIndex]);
}

void UInteractorActorComponent::SelectNearbyInteractionIndex(int32 NewIndex)
{
	this->SelectedInteractionIndex = NewIndex;
	// Notify about selection change and provide pointer to the new selected wrapper and its index
	this->OnChangeSelectedInteractionIndex.Broadcast(this->SelectedInteractionIndex, this->Interactions[SelectedInteractionIndex]);
}

void UInteractorActorComponent::ExecuteSelectedInteractionAction(AActor* InteractedActor)
{   // Check NearbyIteractions list is not empty
	if (this->Interactions.Num() == 0) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionEmptyInteractions);
		return; // if interactions list empty
	}
	// Check SelectedInteractionItem is valid
	if (this->Interactions.Num() < SelectedInteractionIndex) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionInvalidSelection);
		return; // if selection index is higher than interactions count
	}
	// Get selected NearbyInteraction
	auto Wrapper = this->Interactions[this->SelectedInteractionIndex];
	// Call event that actor was interacted
	this->OnActorInteracted.Broadcast(Wrapper->InteractableActor);
	ExecuteSelectedInteractionActionInternal(InteractedActor, Wrapper);
}

void UInteractorActorComponent::ExecuteSelectedInteractionActionInternal(AActor* InteractedActor, UInteractionWrapper* Wrapper)
{   // Check is actor is interactable
	if (!Wrapper->InteractableActor->GetClass()->ImplementsInterface(UInteractableSphereComponentHolder::StaticClass())) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionNotInteractableInterface);
		return; // if interactable actor doesn't implements InteractableSphereComponentHolder
	}
	auto InteractableSphereComponent = IInteractableSphereComponentHolder::Execute_GetInteractableSphereComponent(Wrapper->InteractableActor);
	if (!IsValid(InteractableSphereComponent)) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionNotInteractablePointer);
		return; // if interactable actor doesn't provides InteractableSphereComponent
	}

	// Invoke default interaction action event
	InteractableSphereComponent->OnInteractionAction.Broadcast(InteractedActor, Wrapper);

	// Invoke inventory item action if inventorable
	if (Wrapper->InteractableActor->GetClass()->ImplementsInterface(UInventorableActorComponentHolder::StaticClass())) {
		auto InventorableActorComponent = IInventorableActorComponentHolder::Execute_GetInventorableActorComponent(Wrapper->InteractableActor);
		if (IsValid(InventorableActorComponent)) {
			InventorableActorComponent->ExecuteInventoryItemAction(this->GetOwner());
		}
	}

	// When all interactions was finished - invoke event on the interacted component and current component to finalize it
	this->OnInteractionFinished.Broadcast(InteractedActor, Wrapper);
	InteractableSphereComponent->OnInteractionFinished.Broadcast(InteractedActor, Wrapper);
}
