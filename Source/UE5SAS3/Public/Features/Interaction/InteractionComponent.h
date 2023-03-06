// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Math/Vector.h"
#include "InteractionComponent.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UInteractionComponent : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE5SAS3_API IInteractionComponent
{
	GENERATED_BODY()

	// This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	FVector GetWorldLocationFromOwnerActor();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Interaction")
	void OnInteractionComponentAdded();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Interaction")
	void OnInteractionComponentRemoved();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Interaction")
	void OnInteractionComponentSelected();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Interaction")
	void OnInteractionComponentUnselected();

	/** Interaction with component owner should be performed */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Interaction")
	void Interact(const TScriptInterface<IInteractorComponent>& TriggerComponent);
};
