// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FBattleResultStructure.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct SAS3_API FBattleResultStructure
{
	GENERATED_BODY()
public:

	/* Indicates when battle is started */
	UPROPERTY(BlueprintReadWrite)
	bool IsStarted;

	/* Indicates when battle is finished */
	UPROPERTY(BlueprintReadWrite)
	bool IsFinished;

	/* Is last battle winned?*/
	UPROPERTY(BlueprintReadWrite)
	bool IsWinned;

	FBattleResultStructure();

	virtual ~FBattleResultStructure();
};
