// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponent/InventoryActorComponent.h"

// Sets default values for this component's properties
UInventoryActorComponent::UInventoryActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// Intialize default inventory settings
	this->InventorySize = 10;
	this->StackSize = 10;
}


// Called when the game starts
void UInventoryActorComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine) {
		auto message = FString::Printf(TEXT("Initial stack size %i"), this->StackSize);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, message);
	}
}


// Called every frame
void UInventoryActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

