// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractorComponent.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractorComponent : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE5SAS3_API IInteractorComponent
{
	GENERATED_BODY()

	// This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Interaction")
	void AddInteractionComponent(const TScriptInterface<IInteractionComponent> &Component);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Interaction")
	void RemoveInteractionComponent(const TScriptInterface<IInteractionComponent> &Component);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Interaction")
	void GetInteractionComponents(TArray<TScriptInterface<IInteractionComponent>>& Components);

};
