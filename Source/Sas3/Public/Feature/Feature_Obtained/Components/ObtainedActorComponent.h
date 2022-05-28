// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObtainedActorComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddObtainedItem, UInventoryItemStructureWrapper*, Wrapper);

UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UObtainedActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Default constructor
	UObtainedActorComponent();
	// Default virtual constructor
	virtual ~UObtainedActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Calls when inventory item should be added to the obtained items list
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Obtained Delegates")
	FOnAddObtainedItem OnAddObtainedItem;
};
