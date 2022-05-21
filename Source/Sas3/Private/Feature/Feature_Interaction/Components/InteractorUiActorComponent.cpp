// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Interaction/Components/InteractorUiActorComponent.h"

// Sets default values for this component's properties
UInteractorUiActorComponent::UInteractorUiActorComponent()
{   // Set this component to be initialized when the game starts, and to be ticked every frame. 
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UInteractorUiActorComponent::BeginPlay()
{
	Super::BeginPlay();
}
