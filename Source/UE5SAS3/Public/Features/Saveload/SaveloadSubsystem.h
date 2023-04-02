// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveloadSubsystem.generated.h"

/**
 * 
 */
UCLASS(Category = "Saveload Feature")
class UE5SAS3_API USaveloadSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Saveload Feature")
	void SaveGameToSlot();

	UFUNCTION(BlueprintCallable, Category = "Saveload Feature")
	void LoadGameFromSlot();
};
