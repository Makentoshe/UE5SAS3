// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class NearbyInteractionType : uint8 {
	None			UMETA(DisplayName = "None"),
	Inventory		UMETA(DisplayName = "Inventory"),
	Environment     UMETA(DisplayName = "Environment"),
};
