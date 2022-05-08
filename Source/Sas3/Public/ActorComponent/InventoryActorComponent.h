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
	// Add provided item to the inventory starting from the new stack
	void AddInventoryItemNewStack(FInventoryItemStructure InventoryItem);

};
