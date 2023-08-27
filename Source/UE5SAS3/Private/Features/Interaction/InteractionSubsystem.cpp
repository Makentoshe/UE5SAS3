// Fill out your copyright notice in the Description page of Project Settings.

#include "Features/Interaction/InteractionSubsystem.h"

#include "Kismet/GameplayStatics.h"


void UInteractionSubsystem::AddInteractionToInteractor(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent)
{
	// Add InteractionComponent to Interactor
	InteractorComponent->Execute_AddInteractionComponent(InteractorComponent.GetObject(), InteractionComponent);

	// Notify InteractionComponent
	InteractionComponent->Execute_OnInteractionComponentAvailable(InteractionComponent.GetObject());
}

void UInteractionSubsystem::RemoveInteractionFromInteractor(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent)
{
	// Remove InteractionComponent from Interactor
	InteractorComponent->Execute_RemoveInteractionComponent(InteractorComponent.GetObject(), InteractionComponent);

	// Notify InteractionComponent
	InteractionComponent->Execute_OnInteractionComponentUnavailable(InteractionComponent.GetObject());
}

void UInteractionSubsystem::Interact(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent)
{
	// Notify InteractorComponent first. This allows to do something before InteractionComponent 
	InteractorComponent->Execute_OnInteractionComponentInteracted(InteractorComponent.GetObject(), InteractionComponent);

	// Notify InteractionComponent that interaction was performed
	InteractionComponent->Execute_OnInteractionComponentInteracted(InteractionComponent.GetObject(), InteractorComponent);
}

void UInteractionSubsystem::InteractSelectedComponent(const TScriptInterface<IInteractorComponent>& InteractorComponent)
{
	// Get SelectedInteractionComponent from InteractionComponent interface
	TScriptInterface<IInteractionComponent> SelectedInteractionComponent;
	InteractorComponent->Execute_GetSelectedInteractionComponent(InteractorComponent.GetObject(), SelectedInteractionComponent);

	// Invoke interaction between components if SelectedInteractionComponent is a valid pointer
	if (SelectedInteractionComponent.GetObject()) {
		Interact(SelectedInteractionComponent, InteractorComponent);
	}
}

void UInteractionSubsystem::Broadcast(FString id) {
	this->OnInteractionSubsystemBroadcastDelegate.Broadcast(id);
}
