// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractorActorComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractorActorComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * Type-safe access to the InteractionActorComponent
 */
class SAS3_API IInteractorActorComponentHolder
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	UInteractorActorComponent* GetInteractorActorComponent();
};
