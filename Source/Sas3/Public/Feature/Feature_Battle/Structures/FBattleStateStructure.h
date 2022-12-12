// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <Sas3/Public/Feature/Feature_Battle/Enums/EBattleState.h>

#include "FBattleStateStructure.generated.h"


USTRUCT(BlueprintType)
struct SAS3_API FBattleStateStructure
{
	GENERATED_BODY()

	/* State of the battle */
	UPROPERTY(BlueprintReadWrite)
	EBattleState State;

	FBattleStateStructure();

	FBattleStateStructure(EBattleState State);

	virtual ~FBattleStateStructure();
};
