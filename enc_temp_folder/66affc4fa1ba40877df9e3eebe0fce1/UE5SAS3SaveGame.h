// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UE5SAS3SaveGame.generated.h"

/**
 * 
 */
UCLASS(Category = "Saveload Feature")
class UE5SAS3_API UUE5SAS3SaveGame : public USaveGame
{
	GENERATED_BODY()

	UUE5SAS3SaveGame();

	UPROPERTY(EditAnywhere)
	FVector PlayerLocation;
};
