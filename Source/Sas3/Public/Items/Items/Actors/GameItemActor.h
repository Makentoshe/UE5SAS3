// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Runtime/Engine/Classes/Components/SphereComponent.h>
#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryItemStructure.h>
#include "GameItemActor.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNearbyInteractionBegin, AActor*, OverlappedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNearbyInteractionEnd, AActor*, OverlappedActor);


/*
 * Most based game item that can be placed on the scene but not this one.
 */
UCLASS(BlueprintType, Abstract)
class SAS3_API AGameItemActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AGameItemActor(); //const
	virtual ~AGameItemActor(); //dest

	// Called when something overlaps SphereComponent
	UFUNCTION(BlueprintCallable)
	void OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Called when something overlaps SphereComponent
	UFUNCTION(BlueprintCallable)
	void OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Contains general info about item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FGameItemStructure GameItem;

	// Sphere collision that declares interaction with the actor
	UPROPERTY(BlueprintReadOnly, Category = Components)
	TObjectPtr<USphereComponent> InteractionSphereComponent;

	UPROPERTY(BlueprintAssignable, Category = "Event Dispatchers")
	FOnNearbyInteractionBegin OnNearbyInteractionBegin;

	UPROPERTY(BlueprintAssignable, Category = "Event Dispatchers")
	FOnNearbyInteractionEnd OnNearbyInteractionEnd;
};
