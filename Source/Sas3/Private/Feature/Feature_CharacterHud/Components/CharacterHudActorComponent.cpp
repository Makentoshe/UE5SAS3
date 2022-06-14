// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_CharacterHud/Components/CharacterHudActorComponent.h"

// Sets default values for this component's properties
UCharacterHudActorComponent::UCharacterHudActorComponent()
{   // Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}

/* Component Lifecycle */

void UCharacterHudActorComponent::OnRegister()
{
	Super::OnRegister();

	this->OwnerPawn = Cast<APawn>(this->GetOwner());
	if (!IsValid(this->OwnerPawn)) {
		this->OnInvalidOwnerPawn.Broadcast(this->GetOwner());
		return;
	}
}

void UCharacterHudActorComponent::BeginPlay()
{
	Super::BeginPlay();

	this->OwnerController = Cast<APlayerController>(this->OwnerPawn->GetController());
	if (!IsValid(this->OwnerController)) {
		this->OnInvalidPlayerController.Broadcast(this->OwnerPawn->GetController());
		return;
	}
}

void UCharacterHudActorComponent::OnUnregister()
{
	Super::OnUnregister();
}

/* ... */

void UCharacterHudActorComponent::AddInteraction(UInteractionWrapper* InteractionWrapper)
{   // Add specified interaction to the hud
	this->InteractionsWidget.Get()->AddInteractionEntry(InteractionWrapper);
	// Show hud to the player if it is hidden right now
	if (!this->InteractionsWidget.Get()->IsVisible()) {
		this->InteractionsWidget.Get()->AddToViewport();
	}
}

void UCharacterHudActorComponent::RemoveInteraction(UInteractionWrapper* InteractionWrapper)
{   // Remove specified interaction from the hud
	this->InteractionsWidget.Get()->RemoveInteractionEntry(InteractionWrapper);
	// Hide hud from the player if it is shown right now
	if (!this->InteractionsWidget.Get()->GetCurrentInteractionsCount()) {
		this->InteractionsWidget.Get()->RemoveFromParent();
	}
}

void UCharacterHudActorComponent::ChangeInteractionSelection(int32 NewIndex)
{
	this->InteractionsWidget.Get()->ChangeInteractionEntrySelection(NewIndex);
}
