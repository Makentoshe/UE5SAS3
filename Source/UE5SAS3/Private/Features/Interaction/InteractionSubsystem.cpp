// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Interaction/InteractionSubsystem.h"

void UInteractionSubsystem::AddInteractionToInteractor(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent)
{
	// Add InteractionComponent to Interactor
	//InteractorComponent->Execute_AddInteractionComponent(InteractorComponent.GetObject(), InteractionComponent);

	//// Invoke InteractionComponent.OnInteractionComponentAvailable
//InteractionComponent.GetInterface()->Execute_OnInteractionComponentAvailable(InteractionComponent.GetObject());
}

void UInteractionSubsystem::RemoveInteractionFromInteractor(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent)
{

}
