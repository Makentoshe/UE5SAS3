// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Features/Saveload/SaveloadComponent.h"

#include "SaveloadComponentHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USaveloadComponentHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE5SAS3_API ISaveloadComponentHolder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void  GetSaveloadComponent(TScriptInterface<ISaveloadComponent>& Component);
};
