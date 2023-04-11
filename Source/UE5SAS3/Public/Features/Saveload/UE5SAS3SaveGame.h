// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Containers/Map.h"

#include "Features/Saveload/FSSaveloadObject.h"

#include "UE5SAS3SaveGame.generated.h"

/**
 * 
 */
UCLASS(Category = "Saveload Feature")
class UE5SAS3_API UUE5SAS3SaveGame : public USaveGame
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, SaveGame, Category = "Saveload Feature", meta = (AllowPrivateAccess = "true"))
	TMap<FName, FSSaveloadObject> SaveloadObjects;

public:

	FORCEINLINE void AddSaveloadObject(const FName Identifier, const FSSaveloadObject Object) { this->SaveloadObjects.Add(Identifier, Object); }
	FORCEINLINE struct FSSaveloadObject GetSaveloadObject(const FName Identifier) { return this->SaveloadObjects[Identifier]; }
	FORCEINLINE TMapBase<FName, FSSaveloadObject, FDefaultSetAllocator, TDefaultMapHashableKeyFuncs<FName, FSSaveloadObject, false>>::TConstIterator GetSaveloadObjectsIterator() const 
	{
		return SaveloadObjects.CreateConstIterator();
	}


	// Default constructor
	UUE5SAS3SaveGame();

	// Default destructor
	// Note: virtual for the super call
	virtual ~UUE5SAS3SaveGame();

};
