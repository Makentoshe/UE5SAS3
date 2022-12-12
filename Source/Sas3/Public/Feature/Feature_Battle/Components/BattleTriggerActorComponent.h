// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include <Sas3/Public/Feature/Feature_Battle/Structures/FBattleStateStructure.h>

#include "BattleTriggerActorComponent.generated.h"


UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UBattleTriggerActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBattleTriggerActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	// True if this component owner starts the battle
	UPROPERTY(BlueprintReadWrite)
	bool IsTriggered;

};
