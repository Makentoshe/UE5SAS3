// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EBattleState : uint8 
{	
	Initialized				UMETA(DisplayName = "Initialized"),
	Started					UMETA(DisplayName = "Started"),
	FinishedFailure			UMETA(DisplayName = "Finished with Failure"),
	FinishedSuccess			UMETA(DisplayName = "Finished with Success"),
	Uninitialized			UMETA(DisplayName = "Uninitialized"),
};
