// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Feature/Feature_Interaction/Components/InteractableSphereComponent.h"
#include "InteractableSphereComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractableSphereComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * Type-safe access to the InteractableActorComponent
 */
class SAS3_API IInteractableSphereComponentHolder
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	UInteractableSphereComponent* GetInteractableSphereComponent();
};
