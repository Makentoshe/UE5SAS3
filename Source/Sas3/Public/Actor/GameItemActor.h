// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Sas3/Public/Structure/FGameItemStructure.h>
#include <Runtime/Engine/Classes/Components/SphereComponent.h>
#include "GameItemActor.generated.h"

/*
 * Most based game item that can be placed on the scene.
 */
UCLASS(BlueprintType)
class SAS3_API AGameItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameItemActor();

public:
	// Contains general info about item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FGameItemStructure GameItem;

	// Sphere collision that declares interaction with the actor
	UPROPERTY(BlueprintReadOnly, Category = Components)
	TObjectPtr<USphereComponent> InteractionSphereComponent;
};
