// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include <Sas3/Public/Feature/Feature_Interaction/Structure/FInteractionStructure.h>
#include <Sas3/Public/Feature/Feature_Interaction/Components/InteractableSphereComponent.h>


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
	UInteractionWrapper(FInteractionStructure& Structure, UInteractableSphereComponent* Component);

	// Default virtual destructor
	virtual ~UInteractionWrapper();

	// Wrapped structure
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn = "true"))
	FInteractionStructure InteractionStructure;

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	TObjectPtr<UInteractableSphereComponent> InteractableComponent;

	// Allows to compare 2 Wrappers
	bool operator==(UInteractionWrapper* Wrapper);
};
