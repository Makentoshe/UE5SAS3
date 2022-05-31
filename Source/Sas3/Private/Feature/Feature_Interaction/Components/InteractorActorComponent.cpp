// Fill out your copyright notice in the Description page of Project Settings.

#include "Feature/Feature_Interaction/Components/InteractorActorComponent.h"
#include "Feature/Feature_Inventory/Interfaces/InventoryActorComponentHolder.h"

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
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::RemoveCantRemoveWrapperFromList);
		//auto text = TEXT("UInteractorActorComponent: Cant remove UNearbyInteractionWrapper from the list");
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, text);
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

	this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::RemoveCantFindWrapperInList);
	// If we don't find wrapper - notify about it
	//auto text = TEXT("UInteractorActorComponent: Cant find UNearbyInteractionWrapper for provided FNearbyInteractionStructure");
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, text);
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
	this->RemoveNearbyInteractionWrapper(Wrapper);
	// Fix selection: decrease index if it out of the length bound
	this->SelectedInteractionIndex = FMath::Max(FMath::Min(this->NearbyInteractions.Num() - 1, this->SelectedInteractionIndex), 0);
	// Invoke change selection event	
	auto NewSelectedWrapper = this->NearbyInteractions[this->SelectedInteractionIndex];
	this->OnChangeSelectedInteractionIndex.Broadcast(this->SelectedInteractionIndex, NewSelectedWrapper);
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

void UInteractorActorComponent::ExecuteSelectedNearbyInteraction(AActor* InteractedActor)
{   // Check NearbyIteractions list is not empty
	if (this->NearbyInteractions.Num() == 0) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionEmptyInteractionsList);
		return;
	}
	// Check SelectedInteractionItem is valid
	if (this->NearbyInteractions.Num() < SelectedInteractionIndex) {
		this->OnNearbyInteractionIssue.Broadcast(ENearbyInteractionIssue::InteractionSelectionIssue);
		return;
	}
	// Get selected NearbyInteraction
	auto Wrapper = this->NearbyInteractions[this->SelectedInteractionIndex];
	// Call event that GameItem was interacted
	this->OnGameItemInteracted.Broadcast(Wrapper->NearbyInteractionStructure.Actor);

	switch (Wrapper->NearbyInteractionStructure.NearbyInteractionType) {
	case NearbyInteractionType::None:
		NearbyInteractionNone(Wrapper, InteractedActor);
		break;
	case NearbyInteractionType::Inventory:
		NearbyInteractionInventory(Wrapper, InteractedActor);
		break;
	case NearbyInteractionType::Environment:
		NearbyInteractionEnvironment(Wrapper, InteractedActor);
		break;
	}

	// Notify GameItem that it was interacted
	Wrapper->NearbyInteractionStructure.Actor->OnGameItemInteracted.Broadcast(InteractedActor);
}

