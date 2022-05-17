// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/GameItemActor.h"

// Sets default values
AGameItemActor::AGameItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Initialize SphereComponent
	this->InteractionSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	InteractionSphereComponent->InitSphereRadius(128.0f);
	InteractionSphereComponent->SetCollisionProfileName("Trigger");
	RootComponent = InteractionSphereComponent;
}
