// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/ActorComponent/InventoryActorComponent.h>
#include "InteractorUiActorComponent.generated.h"

UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UInteractorUiActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractorUiActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
public:

};
