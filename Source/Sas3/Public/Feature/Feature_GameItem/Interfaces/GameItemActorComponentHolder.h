// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include <Sas3/Public/Feature/Feature_GameItem/Components/GameItemActorComponent.h>
#include "GameItemActorComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameItemActorComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * Type-safe access to the GameItemActorComponent
 */
class SAS3_API IGameItemActorComponentHolder
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	UGameItemActorComponent* GetGameItemActorComponent();
};
