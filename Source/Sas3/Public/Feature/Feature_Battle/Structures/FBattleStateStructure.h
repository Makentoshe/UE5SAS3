// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <Sas3/Public/Feature/Feature_Battle/Enums/EBattleState.h>

#include "FBattleStateStructure.generated.h"


/**
 * When IsBattleStarted and IsBattleFinished false - battle wasn't started
 */
USTRUCT(BlueprintType)
struct SAS3_API FBattleStateStructure
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	EBattleState State;

	FBattleStateStructure();

	FBattleStateStructure(EBattleState State);

	virtual ~FBattleStateStructure();
};
