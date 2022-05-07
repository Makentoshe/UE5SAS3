// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Structure/FInventoryItemStructure.h>
#include "InventoryActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SAS3_API UInventoryActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public: 
	// Defines how many stacks of items might be in the inventory
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory Settings")
	int32 InventorySize;

	// Defines how many items might be in one stack
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory Settings")
	int32 StackSize;

private:
	// Contains all items in the inventory
	UPROPERTY()
	TArray<FInventoryItemStructure> Inventory;

public:
	// Add provided item to the inventory
	UFUNCTION(BlueprintCallable)
	void AddInventoryItem(FInventoryItemStructure InventoryItem);
	
	// Returns all items currently placed in the inventory
	UFUNCTION(BlueprintCallable)
	TArray<FInventoryItemStructure> GetInventoryItems();

private:
	// Add unstackable inventory item to the inventory. 
	// Here we don't care about finding an unstacked item in the inventory
	void AddInventoryItemUnstackable(FInventoryItemStructure InventoryItem);

	// Add stackable inventory item to the inventory. 
	// Here we should find nearest unstacked same-type item and fill it. repeat
	void AddInventoryItemStackable(FInventoryItemStructure InventoryItem);

	// Add inventory item to the Inventory starting from the new stack
	// Example: Adding 15 items for stack(10) cause adding 2 stacks 10 and 5
	void AddInventoryItemNewStack(FInventoryItemStructure InventoryItem);

	// Add item to the inventory firstly trying to append to the existsing stacks
	// Example: If inventory contains existing elements w/o full stacks(e.g. 8) 
	// it will try to find this stack and firstly append items until stack will not be full.
	void AddInventoryItemAppend(FInventoryItemStructure InventoryItem);


};
