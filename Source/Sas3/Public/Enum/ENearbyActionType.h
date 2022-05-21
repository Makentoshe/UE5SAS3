// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ENearbyActionType: uint8
{
	/* None means that the object wasn't initialized yet. Some kind of null */
	None UMETA(DisplayName = "None"),

	/* Nearby action will be applied to the character inventory (pickupable item)*/
	Inventory UMETA(DisplayName = "Inventory Action"),

	/* Nearby action will be applied to the environment object (lever, button, etc)*/
	Environment UMETA(DisplayName = "Environment Action"),
};
