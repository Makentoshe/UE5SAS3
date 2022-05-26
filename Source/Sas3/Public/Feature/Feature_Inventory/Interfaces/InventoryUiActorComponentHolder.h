// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryUiActorComponent.h>
#include "InventoryUiActorComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInventoryUiActorComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SAS3_API IInventoryUiActorComponentHolder
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	UInventoryUiActorComponent* GetInventoryUiActorComponent();
};
