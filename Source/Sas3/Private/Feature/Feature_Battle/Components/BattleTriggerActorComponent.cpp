// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"

#include "Feature/Feature_Battle/Components/BattleTriggerActorComponent.h"

#include <Sas3/Public/Feature/Feature_Battle/Subsystems/BattleGameInstanceSubsystem.h>


// Sets default values for this component's properties
UBattleTriggerActorComponent::UBattleTriggerActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UBattleTriggerActorComponent::BeginPlay()
{
	Super::BeginPlay();
}
