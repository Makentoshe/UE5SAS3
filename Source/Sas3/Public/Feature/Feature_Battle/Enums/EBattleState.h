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
	Finished				UMETA(DisplayName = "Finished"),
	Uninitialized			UMETA(DisplayName = "Uninitialized"),
};
