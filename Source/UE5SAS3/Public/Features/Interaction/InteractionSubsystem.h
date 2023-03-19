// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "Features/Interaction/InteractionComponent.h"
#include "Features/Interaction/InteractorComponent.h"

#include "InteractionSubsystem.generated.h"

/**
 * Subsystem works as Mediator between InteractorComponent and InteractionComponent
 */
UCLASS()
class UE5SAS3_API UInteractionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:

	/** Adds Interaction component to Interactor and notifies both components about it */
	UFUNCTION(BlueprintCallable)
	void AddInteractionToInteractor(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent);
	
	/** Removes Interaction component from Interactor and notifies both components about it */
	UFUNCTION(BlueprintCallable)
	void RemoveInteractionFromInteractor(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent);


	/** Invokes interaction between InteractorComponent and InteractionComponent and notifies both components about it */
	UFUNCTION(BlueprintCallable)
	void Interact(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent);

	/** Invokes interaction between InteractorComponent and its selected InteractionComponent and notifies both components about it */
	UFUNCTION(BlueprintCallable)
	void InteractSelectedComponent(const TScriptInterface<IInteractorComponent>& InteractorComponent);
};
