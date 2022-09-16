// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include <Sas3/Public/Feature/Feature_Saveload/Structure/FSaveloadActorStructure.h>
#include "SaveGameBase.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract)
class SAS3_API USaveGameBase : public USaveGame
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintType)
	void ClearSerializedActors();

	UFUNCTION(BlueprintType)
	void AddSerializedActor(FSaveloadActorStructure Structure);

	UFUNCTION(BlueprintType)
	TArray<FSaveloadActorStructure> GetSerializedActors();

private:
	UPROPERTY()
	TArray<FSaveloadActorStructure> SerializedActors;
};
