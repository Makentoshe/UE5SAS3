// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include <Sas3/Public/Structure/FInventoryItemStructure.h>
#include "InventoryItemActor.generated.h"

UCLASS()
class SAS3_API AInventoryItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called when something overlaps SphereComponent
	UFUNCTION(BlueprintCallable)
	void OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// Called when something overlaps SphereComponent
	UFUNCTION(BlueprintCallable)
	void OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Called on input event call
	UFUNCTION(BlueprintCallable)
	void OnItemPickupAction();

//private:
	// Sphere collision that triggers ability to pick up an item
	UPROPERTY(BlueprintReadOnly, Category = Components)
	TObjectPtr<USphereComponent> SphereComponent;
	
	// Actor that overlaps SphereComponent
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AActor> PlayerCharacter;

	// Contains info about item
	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadOnly, Category = "Inventory Item")
	FInventoryItemStructure InventoryItem;
};
