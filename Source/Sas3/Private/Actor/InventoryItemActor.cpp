// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/InventoryItemActor.h"
#include <Sas3/Public/Interface/InventoryActorComponentHolder.h>

// Sets default values
AInventoryItemActor::AInventoryItemActor()
{
 	// Set this actor to call Tick() every frame.
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
	this->SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(128.0f);
	SphereComponent->OnComponentBeginOverlap.Add(FScriptDelegateSphereComponentBeginOverlap);
	SphereComponent->OnComponentEndOverlap.Add(FScriptDelegateSphereComponentEndOverlap);
}

// Signature for OnBeginOverlap for SphereComponent
void AInventoryItemActor::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{	// Check actor implements Inventory Component interface
	if (!OtherActor->GetClass()->ImplementsInterface(UInventoryActorComponentHolder::StaticClass())) return;
	// Add current item to the pickupable items list
	IInventoryActorComponentHolder::Execute_GetInventoryActorComponent(OtherActor)->AddPickupableInventoryItem(InventoryItem, this);
}

// Signature for OnEndOverlap for SphereComponent
void AInventoryItemActor::OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{   // Check actor implements Inventory Component interface
	if (!OtherActor->GetClass()->ImplementsInterface(UInventoryActorComponentHolder::StaticClass())) return;
	// Add current item to the pickupable items list
	IInventoryActorComponentHolder::Execute_GetInventoryActorComponent(OtherActor)->RemovePickupableInventoryItem(InventoryItem, this);
}

// Signature for OnKeyEventPressed(E)
void AInventoryItemActor::OnItemPickupAction() 
{   // Check actor implements Inventory Component interface
	if (!PlayerCharacter->GetClass()->ImplementsInterface(UInventoryActorComponentHolder::StaticClass())) return;
	// Add item to the inventory
	IInventoryActorComponentHolder::Execute_GetInventoryActorComponent(PlayerCharacter)->AddInventoryItem(InventoryItem);
	// Remove actor from the scene
	K2_DestroyActor();
}
