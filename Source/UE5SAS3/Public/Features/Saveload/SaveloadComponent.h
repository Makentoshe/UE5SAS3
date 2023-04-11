// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Features/Saveload/FSSaveloadObject.h"

#include "SaveloadComponent.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Category = "Saveload Feature")
class USaveloadComponent : public UInterface
{
	GENERATED_BODY()
};

/**
 * Component allows to serialize/deserialize owner actor state
 * 
 * This component is connected with other features which state can be stored, like inventory or other stuff.
 */
class UE5SAS3_API ISaveloadComponent
{
	GENERATED_BODY()

public:

	// Returns owner actor
	UFUNCTION(BlueprintNativeEvent, Category = "Saveload Feature")
	AActor* GetOwnerActor();

	// Returns SaveloadObject based on owner actor
	UFUNCTION(BlueprintNativeEvent, Category = "Saveload Feature")
	void Serialize(FSSaveloadObject& SaveloadObject);

	// Restores owner actor state from SaveloadObject
	UFUNCTION(BlueprintNativeEvent, Category = "Saveload Feature")
	void Deserialize(const FSSaveloadObject& SaveloadObject);
};
