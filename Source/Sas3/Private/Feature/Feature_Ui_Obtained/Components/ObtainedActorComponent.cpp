// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Ui_Obtained/Components/ObtainedActorComponent.h"

// Sets default values for this component's properties
UObtainedActorComponent::UObtainedActorComponent()
{   // Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}

UObtainedActorComponent::~UObtainedActorComponent()
{
}

// Called when the game starts
void UObtainedActorComponent::BeginPlay()
{
	Super::BeginPlay();
}
