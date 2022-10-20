// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"

#include <Sas3/Public/Feature/Feature_Interaction/Structure/FInteractionStructure.h>

#include "InteractableSphereComponent.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractableComponentOnInteractionFinished);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractableComponentOnInteractionStarted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractableComponentInteractionSelectionChanged, AActor*, InteractedActor, bool, IsActorSelected);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractableComponentOnAddInteractionWrapper, AActor*, InteractorActor, FInteractionStructure, Structure);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractableComponentOnRemoveInteractionWrapper, AActor*, InteractorActor, FInteractionStructure, Structure);


/**
 * SphereComponent enables interaction on collision events
 * 
 * Add this component for the actor that should be interactable and in BP declare begin and end overlaps
 */
UCLASS(BlueprintType, Abstract, Blueprintable, meta = (BlueprintSpawnableComponent))
class SAS3_API UInteractableSphereComponent : public USphereComponent
{
	GENERATED_BODY()
	
	// Default constructor
	UInteractableSphereComponent();

	// Called when a component is registered, after Scene is set, but before CreateRenderState_Concurrent or OnCreatePhysicsState are called.
	virtual void OnRegister() override;

	// Called when a component is unregistered. Called after DestroyRenderState_Concurrent and OnDestroyPhysicsState are called.
	virtual void OnUnregister() override;

	// Default virtual destructor
	virtual ~UInteractableSphereComponent();


public:
	// Called when something overlaps SphereComponent
	UFUNCTION(BlueprintCallable)
	void OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Called when something overlaps SphereComponent
	UFUNCTION(BlueprintCallable)
	void OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Called on owner selection. 
	UFUNCTION(BlueprintCallable)
	void SelectInteractableOwner(AActor* InteractedActor, bool SelectionValue);

	// Called before all interaction events
	UFUNCTION(BlueprintCallable)
	void InitializeInteraction();

	// Called after all interaction events (for example: remove actor from the scene)
	UFUNCTION(BlueprintCallable)
	void FinalizeInteraction();

public:
	// Disables interaction checks if false
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInteractionEnabled;

	// This structure will be passed to interactor component to specify interaction
	UPROPERTY(BlueprintReadWrite)
	FInteractionStructure InteractionStructure;



/****		Assignable Callbacks		****/
public:
	// Called when interaction was started and component should do something
	UPROPERTY(BlueprintAssignable)
	FInteractableComponentOnInteractionStarted OnInteractionStarted;

	// Called when interaction was finished and component can finalize its interaction 
	UPROPERTY(BlueprintAssignable)
	FInteractableComponentOnInteractionFinished OnInteractionFinished;

	// Called when selection was changed for owner actor by interacted actor
	UPROPERTY(BlueprintAssignable)
	FInteractableComponentInteractionSelectionChanged OnInteractionSelectedChanged;

	// Called when interaction should be added to the possible interactions list
	UPROPERTY(BlueprintAssignable)
	FInteractableComponentOnAddInteractionWrapper OnAddInteractionWrapper;

	// Called when interaction should be removed from the possible interactions list
	UPROPERTY(BlueprintAssignable)
	FInteractableComponentOnRemoveInteractionWrapper OnRemoveInteractionWrapper;

};
