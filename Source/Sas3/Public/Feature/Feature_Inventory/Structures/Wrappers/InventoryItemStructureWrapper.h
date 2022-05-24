// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryItemStructure.h>
#include "InventoryItemStructureWrapper.generated.h"

/**
 * Object for wrapping FInventoryItemStructure for UMG
 */
UCLASS(BlueprintType)
class SAS3_API UInventoryItemStructureWrapper : public UObject
{
	GENERATED_BODY()

public: 
	// Sets default values for this actor's properties
	UInventoryItemStructureWrapper();

	// Constructor with value
	UInventoryItemStructureWrapper(FInventoryItemStructure& Structure);

	virtual ~UInventoryItemStructureWrapper();

	UFUNCTION(BlueprintCallable) // returns a copied InventoryItemStructure
	FInventoryItemStructure GetInventoryItemStructure();

	// Wrapped structure
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInventoryItemStructure InventoryItemStructure;
	
};
