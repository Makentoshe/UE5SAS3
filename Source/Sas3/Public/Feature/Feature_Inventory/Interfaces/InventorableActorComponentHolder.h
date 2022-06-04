// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Feature/Feature_Inventory/Components/InventorableActorComponent.h"
#include "InventorableActorComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInventorableActorComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * Type-safe access to the InventorableActorComponent
 */
class SAS3_API IInventorableActorComponentHolder
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	UInventorableActorComponent* GetInventorableActorComponent();
};
