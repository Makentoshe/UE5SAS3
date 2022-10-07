// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include <Feature/Feature_Inventory/Structures/FInventoryMetaStructure.h>
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryActorComponent.h>

#include "InventorableActorComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventorableComponentOnInventoryItemAction, UInventoryActorComponent*, InventoryComponent);


UCLASS(BlueprintType, Abstract, Blueprintable, meta = (BlueprintSpawnableComponent))
class SAS3_API UInventorableActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Default constructor
	UInventorableActorComponent();
	// Default virtual descructor
	virtual ~UInventorableActorComponent();

	// Called to execute inventory item action
	UFUNCTION(BlueprintCallable)
	void ExecuteInventoryItemAction(UInventoryActorComponent* InventoryComponent);

protected:

	UFUNCTION(BlueprintCallable)
	UInventoryItemStructureWrapper* CreateInventoryItemWrapper(FName Title);

public:

	// Holds meta info about item usefull for inventory feature
	UPROPERTY(BlueprintReadWrite)
	FInventoryMetaStructure InventoryMeta;

	UPROPERTY(BlueprintAssignable)
	FInventorableComponentOnInventoryItemAction OnInventoryItemAction;

};
