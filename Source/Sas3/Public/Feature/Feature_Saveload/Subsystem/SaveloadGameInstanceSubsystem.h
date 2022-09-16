// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include <Sas3/Public/Feature/Feature_Saveload/Structure/FSaveloadSlotStructure.h>
#include <Sas3/Public/Feature/Feature_Saveload/Structure/FSaveloadActorStructure.h>
#include "SaveloadGameInstanceSubsystem.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGeneralSaveGameInstanceCreated, USaveGameGeneral*, SaveGameGeneral);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorSerialized, AActor*, SerializedActor, FSaveloadActorStructure, Structure);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorDeserialized, FSaveloadActorStructure, Structure);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAsyncSaveGameCompleted, const FString&, SlotName, const int32, UserIndex, bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAsyncSaveGameStarted, FSaveloadSlotStructure, Structure, USaveGameGeneral*, SaveGameGeneral);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAsyncLoadGameStarted, FSaveloadSlotStructure, Structure);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAsyncLoadGameCompleted, USaveGameGeneral*, LoadGameGeneral);


/**
 * 
 */
UCLASS(BlueprintType, DisplayName = "SaveloadSubsystem")
class SAS3_API USaveloadGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable)
	FSaveloadSlotStructure GetCurrentGeneralSaveloadSlot();

	UFUNCTION(BlueprintCallable)
	void SetCurrentGeneralSaveloadSlot(FSaveloadSlotStructure Structure);

	UFUNCTION(BlueprintCallable)
	void CreateCurrentGeneralSaveload(FString SaveGameSlotTitle);

	UFUNCTION(BlueprintCallable)
	void SaveCurrentGeneralSaveloadSlot();

	UFUNCTION(BlueprintCallable)
	void LoadCurrentGeneralSaveloadSlot();

private:

	UFUNCTION()
	void OnAsyncSaveGame(const FString& SlotName, const int32 UserIndex, bool bSuccess);

	UFUNCTION()
	void OnAsyncLoadGame(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData);

public:
	UPROPERTY(BlueprintAssignable)
	FOnGeneralSaveGameInstanceCreated OnGeneralSaveGameInstanceCreated;

	UPROPERTY(BlueprintAssignable)
	FOnActorSerialized OnActorSerialized;

	UPROPERTY(BlueprintAssignable)
	FOnActorDeserialized OnActorDeserialized;

	UPROPERTY(BlueprintAssignable)
	FOnAsyncSaveGameCompleted OnAsyncSaveGameCompleted;
	
	UPROPERTY(BlueprintAssignable)
	FOnAsyncSaveGameStarted OnAsyncSaveGameStarted;

	UPROPERTY(BlueprintAssignable)
	FOnAsyncLoadGameStarted OnAsyncLoadGameStarted;

	UPROPERTY(BlueprintAssignable)
	FOnAsyncLoadGameCompleted OnAsyncLoadGameCompleted;

private:
	UPROPERTY()
	FSaveloadSlotStructure CurrentGeneralSaveloadSlot;
	
};
