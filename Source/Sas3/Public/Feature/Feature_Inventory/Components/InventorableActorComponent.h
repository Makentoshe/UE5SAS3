// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Feature/Feature_Inventory/Structures/FInventoryMetaStructure.h>
#include "InventorableActorComponent.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemAction, AActor*, InventoryActor, UInventoryItemStructureWrapper*, InventoryItemWrapper);

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
	void ExecuteInventoryItemAction(AActor* InventoryActor);

protected:

	UFUNCTION(BlueprintCallable)
	UInventoryItemStructureWrapper* GetInventoryItemWrapper(FName Title);

public:

	// Called when inventory action occurs
	UPROPERTY(BlueprintAssignable)
	FOnInventoryItemAction OnInventoryItemAction;



/****		InventoryMetaStructure		****/
public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FInventoryMetaStructure GetInventoryMetaStructure();

	UFUNCTION(BlueprintCallable)
	void SetInventoryMetaStructure(FInventoryMetaStructure Structure);

private:
	// Holds meta info about item usefull for inventory feature
	UPROPERTY()
	FInventoryMetaStructure InventoryMeta;

};
