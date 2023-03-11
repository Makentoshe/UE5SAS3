// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Interaction/InteractionSphereComponent.h"

FVector UInteractionSphereComponent::GetWorldLocationFromOwnerActor_Implementation()
{
	return this->GetOwner()->GetActorLocation();
}

void UInteractionSphereComponent::OnInteractionComponentAvailable_Implementation()
{
	// If interaction already available: do nothing
	if (this->IsAvailable) return;

	// Mark component as available to interaction
	this->IsAvailable = true;

	// Send event if we want todo something in blueprints, for example
	this->OnInteractionComponentAvailableDelegate.Broadcast();
}

void UInteractionSphereComponent::OnInteractionComponentUnavailable_Implementation()
{
	// If interaction already unavailable: do nothing
	if (!this->IsAvailable) return;

	// Mark component as not available to interaction
	this->IsAvailable = false;

	// Send event if we want todo something in blueprints, for example
	this->OnInteractionComponentUnavailableDelegate.Broadcast();
}

void UInteractionSphereComponent::OnInteractionComponentSelected_Implementation()
{
	// If component already selected: do nothing
	if (this->IsSelected) return;

	// Mark component as selected
	this->IsSelected = true;

	// Send event if we want todo something in blueprints, for example
	this->OnInteractionComponentSelectedDelegate.Broadcast();
}

void UInteractionSphereComponent::OnInteractionComponentUnselected_Implementation()
{
	// If component already unselected: do nothing
	if (!this->IsSelected) return;

	// Mark component as unselected
	this->IsSelected = false;

	// Send event if we want todo something in blueprints, for example
	this->OnInteractionComponentUnselectedDelegate.Broadcast();
}

void UInteractionSphereComponent::Interact_Implementation(const TScriptInterface<IInteractorComponent>& InteractorComponent)
{
	// We can delegate this method to blueprints
	this->OnInteractionComponentInteractDelegate.Broadcast(InteractorComponent);
}
