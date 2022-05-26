// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Inventory/Components/InventoryUiActorComponent.h"

void UInventoryUiActorComponent::OnRegister()
{
	Super::OnRegister();

	this->OwnerPawn = Cast<APawn>(GetOwner());
	if (!IsValid(this->OwnerPawn)) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Can't cast Owner to APawn"));
		return;
	}
}

void UInventoryUiActorComponent::BeginPlay()
{
	Super::BeginPlay();

	this->OwnerController = Cast<APlayerController>(this->OwnerPawn->GetController());
	if (!IsValid(this->OwnerController)) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Can't cast AController to APlayerController"));
		return;
	}
}

void UInventoryUiActorComponent::OnUnregister()
{
	Super::OnUnregister();
}

// Sets default values for this component's properties
UInventoryUiActorComponent::UInventoryUiActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}
