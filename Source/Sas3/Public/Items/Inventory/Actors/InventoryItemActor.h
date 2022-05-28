// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FNearbyInteractionStructure.h>
#include <Sas3/Public/Items/Inventory/Structures/FInventoryMetaStructure.h>
#include "Feature/Feature_Inventory/Structures/Wrappers/InventoryItemStructureWrapper.h"
#include <Sas3/Public/Items/Items/Actors/GameItemActor.h>
#include "InventoryItemActor.generated.h"

/* 
 * This actor might be pick upped into the Inventory
 */
UCLASS(BlueprintType)
class SAS3_API AInventoryItemActor : public AGameItemActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryItemActor();

	virtual ~AInventoryItemActor();

	// Returns lazy initialized InventoryItemWrapper
	UFUNCTION(BlueprintCallable)
	UInventoryItemStructureWrapper* GetInventoryItemWrapper();

protected:

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	// Called when selected actor overlaps interaction collision
	UFUNCTION()
	void OnNearbyInteractionEndEvent(AActor* OverlappedActor);

	// Called when selected actor overlaps interaction collision
	UFUNCTION()
	void OnNearbyInteractionBeginEvent(AActor* OverlappedActor);

	// Creates a NearbyInteractionStructure
	UFUNCTION()
	FNearbyInteractionStructure BuildNearbyInteractionStructure();

public:
	// Contains inventory info about item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FInventoryMetaStructure InventoryMeta;

private:
	// Lazy property from GetInventoryItemWrapper method
	UPROPERTY()
	TObjectPtr<UInventoryItemStructureWrapper> InventoryItemWrapper;
};
