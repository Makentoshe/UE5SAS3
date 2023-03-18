// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "Features/Interaction/InteractionComponent.h"
#include "Features/Interaction/InteractorComponent.h"

#include "InteractionSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UE5SAS3_API UInteractionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void AddInteractionToInteractor(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent);
	
	UFUNCTION(BlueprintCallable)
	void RemoveInteractionFromInteractor(const TScriptInterface<IInteractionComponent>& InteractionComponent, const TScriptInterface<IInteractorComponent>& InteractorComponent);

};
