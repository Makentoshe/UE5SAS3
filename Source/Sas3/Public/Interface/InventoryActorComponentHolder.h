// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include <Sas3/Public/ActorComponent/InventoryActorComponent.h>
#include "InventoryActorComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInventoryActorComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SAS3_API IInventoryActorComponentHolder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	UInventoryActorComponent* GetInventoryActorComponent();
};
