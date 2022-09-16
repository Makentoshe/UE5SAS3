// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Feature/Feature_Saveload/Structure/FSaveloadActorStructure.h>
#include "SaveloadableActorComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSaveloadableActorComponentOnActorSerialized, FSaveloadActorStructure, Structure);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSaveloadableActorComponentOnActorDeserialized, FSaveloadActorStructure, Structure);

UCLASS(BlueprintType, Abstract, Blueprintable)
class SAS3_API USaveloadableActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USaveloadableActorComponent();

	// Creates a SaveloadActorStructure and returns a copy of it
	UFUNCTION(BlueprintCallable)
	FSaveloadActorStructure GetSaveloadActorStructure();
	
	// Returns a current actor identifier for saveload system
	UFUNCTION(BlueprintCallable)
	FName GetSaveloadActorIdentifier();

	// Consumes a SaveloadActorStructure and restores actor state from it
	UFUNCTION(BlueprintCallable)
	void ConsumeSaveloadActorStructure(FSaveloadActorStructure Structure);

public:

	UPROPERTY(BlueprintAssignable)
	FSaveloadableActorComponentOnActorSerialized OnActorSerialized;

	UPROPERTY(BlueprintAssignable)
	FSaveloadableActorComponentOnActorDeserialized OnActorDeserialized;
};
