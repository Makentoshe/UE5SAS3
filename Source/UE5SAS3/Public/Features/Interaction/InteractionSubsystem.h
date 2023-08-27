// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "Features/Interaction/InteractionComponent.h"
#include "Features/Interaction/InteractorComponent.h"

#include "InteractionSubsystem.generated.h"

/** 
	Delegate for invoking on each interaction invocation for each object subscribed for it 
	Id allows to understood which object invoked it. It can be any string
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionSubsystemBroadcast, FString, Id);

/**
 * Subsystem works as Mediator between InteractorComponent and InteractionComponent
 */
UCLASS()
class UE5SAS3_API UInteractionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	/** Delegate for invoking on each interaction invocation for each object subscribed for it */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	FOnInteractionSubsystemBroadcast OnInteractionSubsystemBroadcastDelegate;

public:

	/** Invokes interaction between InteractorComponent and its selected InteractionComponent and notifies both components about it */
	UFUNCTION(BlueprintCallable)
	void Broadcast(FString id);


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
