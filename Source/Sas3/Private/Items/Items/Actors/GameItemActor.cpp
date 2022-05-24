// Fill out your copyright notice in the Description page of Project Settings.


#include <Sas3/Public/Items/Items/Actors/GameItemActor.h>

// Sets default values
AGameItemActor::AGameItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Initialize OnBeginOverlap delegate for SphereComponent
	FName FNameBeginOverlap("OnSphereComponentBeginOverlap");
	FScriptDelegate FScriptDelegateSphereComponentBeginOverlap;
	FScriptDelegateSphereComponentBeginOverlap.BindUFunction(this, FNameBeginOverlap);

	// Initialize OnEndOverlap delegate for SphereComponent
	FName FNameEndOverlap("OnSphereComponentEndOverlap");
	FScriptDelegate FScriptDelegateSphereComponentEndOverlap;
	FScriptDelegateSphereComponentEndOverlap.BindUFunction(this, FNameEndOverlap);

	// Initialize SphereComponent
	this->InteractionSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	InteractionSphereComponent->InitSphereRadius(128.0f);
	InteractionSphereComponent->SetCollisionProfileName("Trigger");
	RootComponent = InteractionSphereComponent;
	InteractionSphereComponent->OnComponentBeginOverlap.Add(FScriptDelegateSphereComponentBeginOverlap);
	InteractionSphereComponent->OnComponentEndOverlap.Add(FScriptDelegateSphereComponentEndOverlap);
}

AGameItemActor::~AGameItemActor() {}

// Signature for OnBeginOverlap for SphereComponent
void AGameItemActor::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	this->OnNearbyInteractionBegin.Broadcast(OtherActor);
}

// Signature for OnEndOverlap for SphereComponent
void AGameItemActor::OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{   
	this->OnNearbyInteractionEnd.Broadcast(OtherActor);
}