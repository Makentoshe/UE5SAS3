// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryItemStructure.h>
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryUiActorComponent.h>
#include <Sas3/Public/Items/Inventory/Actors/InventoryItemActor.h>
#include <Sas3/Public/Feature/Feature_Inventory/Structures/Wrappers/InventoryItemStructureWrapper.h>
#include "InventoryActorComponent.generated.h"

/* Component declares that the Actor contains Inventory */
UCLASS(BlueprintType)
class SAS3_API UInventoryActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Default constructor
	UInventoryActorComponent();

	//Default virtual destructor
	~UInventoryActorComponent();

public: 
	// Defines how many stacks of items might be in the inventory
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory Settings")
	int32 InventorySize;

protected:

	// Contains all items in the inventory
	UPROPERTY(BlueprintReadOnly)
	TArray<UInventoryItemStructureWrapper*> InventoryItems;

public:
	// Add provided item to the inventory
	UFUNCTION(BlueprintCallable)
	void AddInventoryItemWrapper(UInventoryItemStructureWrapper* Wrapper);

	// Returns all items currently placed in the inventory
	UFUNCTION(BlueprintCallable)
	TArray<UInventoryItemStructureWrapper*> GetInventoryItems();

protected:
	UFUNCTION()
	UInventoryItemStructureWrapper* BuildInventoryItemStructureWrapper(FInventoryItemStructure& Structure);

private:

	// Add provided item to the inventory starting from the new stack
	void AddInventoryItemNewStackWrapper(UInventoryItemStructureWrapper* Wrapper);
};
