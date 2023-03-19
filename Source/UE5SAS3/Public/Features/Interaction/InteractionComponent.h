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
 * Component, inherited this interface can handle interactions from interactor component
 * 
 * 
 * 
 * There is a lifecycle of the InteractionComponent:
 * 
 *                          OnInteractionComponentAvailable								OnInteractionComponentSelected							 Interact
 * Unavailable/Unselected -----------------------------------> Available/Unselected --------------------------------------> Available/Selected -------------->
 *			^														|		^														|
 * 			|			OnInteractionComponentUnvailable			|		|				OnInteractionComponentUnselected		| 
 *			┕-------------------------------------------------------┙		┕-------------------------------------------------------┙
 * 
 */
class UE5SAS3_API IInteractionComponent
{
	GENERATED_BODY()

public:

	/** Interaction component becomes available to interaction and selection */
	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentAvailable();

	/**Interaction component becomes unavailable to interaction and selection */
	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentUnavailable();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentSelected();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentUnselected();

	/** Interaction with component owner should be performed */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentInteracted(const TScriptInterface<IInteractorComponent>& InteractorComponent);
};
