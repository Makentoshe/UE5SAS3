// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FInteractionStructure.h>
#include "InteractionWrapper.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SAS3_API UInteractionWrapper : public UObject
{
	GENERATED_BODY()

public:
	// Default constructor
	UInteractionWrapper();

	// Constructor with value
	UInteractionWrapper(FInteractionStructure& Structure, AActor* Actor);

	// Default virtual destructor
	virtual ~UInteractionWrapper();

	// Returns a copied InteractionStructure
	UFUNCTION(BlueprintCallable)
	FInteractionStructure GetInteractionStructure();

	UFUNCTION(BlueprintCallable)
	AActor* GetInteractableActor();

	// Wrapped structure
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInteractionStructure InteractionStructure;

	// Additionaly wrapped actor
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<AActor> InteractableActor;

	// Allows to compare 2 Wrappers
	bool operator==(UInteractionWrapper* Wrapper);
};
