// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_CharacterHud/Components/CharacterHudActorComponent.h"

// Sets default values for this component's properties
UCharacterHudActorComponent::UCharacterHudActorComponent()
{   // Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}

void UCharacterHudActorComponent::OnRegister()
{
	Super::OnRegister();

	this->OwnerPawn = Cast<APawn>(GetOwner());
	if (!IsValid(this->OwnerPawn)) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Can't cast Owner to APawn"));
		return;
	}
}

void UCharacterHudActorComponent::BeginPlay()
{
	Super::BeginPlay();

	this->OwnerController = Cast<APlayerController>(this->OwnerPawn->GetController());
	if (!IsValid(this->OwnerController)) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Can't cast AController to APlayerController"));
		return;
	}
}

void UCharacterHudActorComponent::OnUnregister()
{
	Super::OnUnregister();
}