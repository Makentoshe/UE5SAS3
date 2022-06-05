// Fill out your copyright notice in the Description page of Project Settings.

#include "Feature/Feature_Interaction/Components/InteractorActorComponent.h"
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

void UInteractorActorComponent::NearbyInteractionNone(UNearbyInteractionWrapper* Wrapper, AActor* InteractedActor)
{
	this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionTypeIsNone);
}

void UInteractorActorComponent::NearbyInteractionInventory(UNearbyInteractionWrapper* Wrapper, AActor* InteractedActor)
{   // Cast to InventoryItemActor
	auto InventoryItemActor = Cast<AInventoryItemActor>(Wrapper->NearbyInteractionStructure.Actor);
	if (InventoryItemActor == nullptr) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionInventoryItemActorCast);
		return;
	}
	// Call event that InventoryItem was interacted
	this->OnInventoryItemInteracted.Broadcast(InventoryItemActor, InteractedActor);
	// Remove InteractionWrapper from the list (hide it)
	//this->RemoveNearbyInteractionWrapper(Wrapper);
	// Fix selection: decrease index if it out of the length bound
	this->SelectedInteractionIndex = FMath::Max(FMath::Min(this->NearbyInteractions.Num() - 1, this->SelectedInteractionIndex), 0);
	// Just return if we cant select anything
	if (this->NearbyInteractions.IsEmpty()) return;
	// Invoke change selection event	
	auto NewSelectedWrapper = this->NearbyInteractions[this->SelectedInteractionIndex];
	//this->OnChangeSelectedInteractionIndex.Broadcast(this->SelectedInteractionIndex, NewSelectedWrapper);
}

void UInteractorActorComponent::NearbyInteractionEnvironment(UNearbyInteractionWrapper* Wrapper, AActor* InteractedActor)
{
	// Cast to InventoryItemActor
	auto EnvironmentItemActor = Cast<AEnvironmentItemActor>(Wrapper->NearbyInteractionStructure.Actor);
	if (EnvironmentItemActor == nullptr) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionEnvironmentItemActorCast);
		return;
	}
	// Call event that EnvironmentItem was interacted
	this->OnEnvironmentItemInteracted.Broadcast(EnvironmentItemActor, InteractedActor);
}

void UInteractorActorComponent::ExecuteSelectedInteractionAction(AActor* InteractedActor)
{   // Check NearbyIteractions list is not empty
	if (this->Interactions.Num() == 0) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionEmptyInteractionsList);
		return;
	}
	// Check SelectedInteractionItem is valid
	if (this->Interactions.Num() < SelectedInteractionIndex) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionSelectionIssue);
		return;
	}
	// Get selected NearbyInteraction
	auto Wrapper = this->Interactions[this->SelectedInteractionIndex];
	// Call event that actor was interacted
	this->OnActorInteracted.Broadcast(Wrapper->InteractableActor);
	ExecuteSelectedInteractionActionInternal(InteractedActor, Wrapper);
	// TODO implement components for environment interactions and inventory interactions
//	switch (Wrapper->NearbyInteractionStructure.NearbyInteractionType) {
//	case NearbyInteractionType::None:
//		NearbyInteractionNone(Wrapper, InteractedActor);
//		break;
//	case NearbyInteractionType::Inventory:
//		NearbyInteractionInventory(Wrapper, InteractedActor);
//		break;
//	case NearbyInteractionType::Environment:
//		NearbyInteractionEnvironment(Wrapper, InteractedActor);
//		break;
//	}
//
//	// Notify GameItem that it was interacted
//	Wrapper->NearbyInteractionStructure.Actor->OnGameItemInteracted.Broadcast(InteractedActor);
}

void UInteractorActorComponent::ExecuteSelectedInteractionActionInternal(AActor* InteractedActor, UInteractionWrapper* Wrapper)
{   // Check if actor is inventorable
	if (Wrapper->InteractableActor->GetClass()->ImplementsInterface(UInventorableActorComponentHolder::StaticClass())) {
		auto InventorableActorComponent = IInventorableActorComponentHolder::Execute_GetInventorableActorComponent(Wrapper->InteractableActor);
		InventorableActorComponent->ExecuteInventoryItemAction(this->GetOwner());
	}

}
