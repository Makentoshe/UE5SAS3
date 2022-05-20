// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include <Sas3/Public/Feature/Feature_Interaction/Components/InteractorUiActorComponent.h>
#include "InteractorUiActorComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractorUiActorComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SAS3_API IInteractorUiActorComponentHolder
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	UInteractorUiActorComponent* GetInteractorUiActorComponent();
};
