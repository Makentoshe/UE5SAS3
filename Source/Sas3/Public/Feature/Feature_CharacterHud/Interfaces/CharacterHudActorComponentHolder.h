// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Feature/Feature_CharacterHud/Components/CharacterHudActorComponent.h"
#include "CharacterHudActorComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCharacterHudActorComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * Type-safe access to the CharacterHudActorComponent
 */
class SAS3_API ICharacterHudActorComponentHolder
{
	GENERATED_BODY()

public:
	UCharacterHudActorComponent GetCharacterHudComponent();
};
