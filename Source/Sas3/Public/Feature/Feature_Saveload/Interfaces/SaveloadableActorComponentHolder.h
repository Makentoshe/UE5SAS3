// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include <Sas3/Public/Feature/Feature_Saveload/Components/SaveloadableActorComponent.h>

#include "SaveloadableActorComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USaveloadableActorComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SAS3_API ISaveloadableActorComponentHolder
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	USaveloadableActorComponent* GetSaveloadableActorComponent();
};
