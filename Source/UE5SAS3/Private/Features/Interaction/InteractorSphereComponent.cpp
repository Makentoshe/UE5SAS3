// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Interaction/InteractorSphereComponent.h"

void UInteractorSphereComponent::AddInteractionComponent_Implementation(const TScriptInterface<IInteractionComponent>& InteractionComponent)
{
	// Add InteractionComponent to available components list
	this->AvailableInteractionComponents.Add(InteractionComponent);

	// Invoke delegate that new InteractionComponent was added
	this->OnInteractionComponentAvailableDelegate.Broadcast(InteractionComponent);
}

void UInteractorSphereComponent::RemoveInteractionComponent_Implementation(const TScriptInterface<IInteractionComponent>& InteractionComponent)
{
	// Remove InteractionComponent from available components list
	this->AvailableInteractionComponents.Remove(InteractionComponent);

	// Invoke delegate that InteractionComponent was removed
	this->OnInteractionComponentUnavailableDelegate.Broadcast(InteractionComponent);
}

void UInteractorSphereComponent::GetInteractionComponents_Implementation(TArray<TScriptInterface<IInteractionComponent>>& InteractionComponents)
{
	InteractionComponents = this->AvailableInteractionComponents;
}
