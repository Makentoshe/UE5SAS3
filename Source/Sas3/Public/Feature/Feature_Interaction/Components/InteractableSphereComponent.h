// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FInteractionStructure.h>
#include "InteractableSphereComponent.generated.h"

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


protected:
	// This structure will be passed to interactor component to specify interaction
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInteractionStructure InteractionStructure;

	// This structure will be passed to interactor component to specify interaction
	UPROPERTY()
	TObjectPtr<UInteractionWrapper> InteractionWrapper;

};
