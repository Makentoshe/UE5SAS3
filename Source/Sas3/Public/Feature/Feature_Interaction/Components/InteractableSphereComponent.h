// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FInteractionStructure.h>
#include "Feature/Feature_Interaction/Enums/EInteractableComponentIssues.h"
#include "InteractableSphereComponent.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractableComponentInteractionFinished, AActor*, InteractedActor, UInteractionWrapper*, InteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractableComponentInteractionAction, AActor*, InteractedActor, UInteractionWrapper*, InteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractableComponentIssue, EInteractableComponentIssues, Reason);


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


protected:

	// Called when something overlaps SphereComponent
	UFUNCTION(BlueprintCallable)
	UInteractionWrapper* GetInteractionWrapper();


public:
	// Disables interaction checks if false
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInteractionEnabled;

	// Called when interaction was started and component should do something
	UPROPERTY(BlueprintAssignable)
	FInteractableComponentInteractionAction OnInteractionAction;

	// Called when interaction was finished and component can finalize its interaction 
	UPROPERTY(BlueprintAssignable)
	FInteractableComponentInteractionFinished OnInteractionFinished;

protected:
	// This structure will be passed to interactor component to specify interaction
	UPROPERTY(BlueprintReadWrite)
	FInteractionStructure InteractionStructure;

	// This structure will be passed to interactor component to specify interaction
	UPROPERTY()
	TObjectPtr<UInteractionWrapper> InteractionWrapper;

	// Cause when any issue occurs to notify about it
	UPROPERTY(BlueprintAssignable)
	FInteractableComponentIssue OnComponentIssues;

};
