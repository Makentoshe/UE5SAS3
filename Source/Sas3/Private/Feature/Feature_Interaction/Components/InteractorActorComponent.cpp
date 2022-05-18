// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Interaction/Components/InteractorActorComponent.h"

// Sets default values for this component's properties
UInteractorActorComponent::UInteractorActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractorActorComponent::InitializeComponent()
{
	Super::InitializeComponent();

	//FString s = FString(TEXT("InitializeComponent"));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, s);
}

// Called when the game starts
void UInteractorActorComponent::BeginPlay()
{
	Super::BeginPlay();

	//FString s = FString(TEXT("Begin play"));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, s);
}
