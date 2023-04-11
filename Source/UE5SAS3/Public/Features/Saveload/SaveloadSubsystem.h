// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveloadSubsystem.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveloadSubsystemSaveGameStarted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveloadSubsystemSaveGameCompleted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveloadSubsystemLoadGameStarted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveloadSubsystemLoadGameCompleted);

/**
 * Subsystem for working with SaveLoad feature
 */
UCLASS(Category = "Saveload Feature")
class UE5SAS3_API USaveloadSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	// Flag indicates current subsystem work
	UPROPERTY(BlueprintReadOnly , Category = "Saveload Feature")
	bool IsSaveloadInProgress;


	UPROPERTY(BlueprintAssignable, Category = "Saveload Feature")
	FOnSaveloadSubsystemSaveGameStarted OnSaveGameStarted;

	UPROPERTY(BlueprintAssignable, Category = "Saveload Feature")
	FOnSaveloadSubsystemSaveGameCompleted OnSaveGameCompleted;

	UPROPERTY(BlueprintAssignable, Category = "Saveload Feature")
	FOnSaveloadSubsystemLoadGameStarted OnLoadGameStarted;

	UPROPERTY(BlueprintAssignable, Category = "Saveload Feature")
	FOnSaveloadSubsystemLoadGameCompleted OnLoadGameCompleted;

public:

	UFUNCTION(BlueprintCallable, Category = "Saveload Feature")
	void SaveGameToSlot();

	UFUNCTION(BlueprintCallable, Category = "Saveload Feature")
	void LoadGameFromSlot();
};
