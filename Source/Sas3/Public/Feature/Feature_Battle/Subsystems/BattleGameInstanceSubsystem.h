// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include <Sas3/Public/Feature/Feature_Battle/Structures/FBattleResultStructure.h>
#include <Sas3/Public/Feature/Feature_Battle/Structures/FBattleStateStructure.h>

#include "BattleGameInstanceSubsystem.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBattleSubsystemBattleStateChanged, FBattleStateStructure, BattleStateStructure);

/**
 * 
 */
UCLASS(BlueprintType, DisplayName = "BattleSubsystem")
class SAS3_API UBattleGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UBattleGameInstanceSubsystem();

	/* Prepare for battle: create and configure enemies and allies */
	UFUNCTION(BlueprintCallable)
	void InitializeBattle();

	/* Enable PlayerController and begin gameplay */
	UFUNCTION(BlueprintCallable)
	void BeginBattle();

	/* Disable PlayerController and save the battle results */
	UFUNCTION(BlueprintCallable)
	void FinishBattleWithSuccess();

	/* Disable PlayerController and save the battle results */
	UFUNCTION(BlueprintCallable)
	void FinishBattleWithFailure();

	/* Uninitialize state and reset variables */
	UFUNCTION(BlueprintCallable)
	void UninitializeBattle();

public:

	UPROPERTY(BlueprintReadWrite)
	FBattleStateStructure BattleState;

	UPROPERTY(BlueprintAssignable)
	FOnBattleSubsystemBattleStateChanged OnBattleStateChanged;
	
};
