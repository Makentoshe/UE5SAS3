// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/InventoryItemActor.h"
#include <Sas3/Public/Interface/InventoryActorComponentHolder.h>

// Sets default values
AInventoryItemActor::AInventoryItemActor()
{
 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
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

// Called when the game starts or when spawned
void AInventoryItemActor::BeginPlay()
{
	Super::BeginPlay();

	// Initialize InputComponent via EnableInput method
	EnableInput(GetWorld()->GetFirstPlayerController());

	// Define item pickup action
	InputComponent->BindKey(EKeys::E, IE_Pressed, this, &AInventoryItemActor::OnItemPickupAction);

	// Disable InputComponent by default
	DisableInput(GetWorld()->GetFirstPlayerController());
}

// Called every frame
void AInventoryItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Signature for OnBeginOverlap for SphereComponent
void AInventoryItemActor::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{   // Enable PlayerController inputs
	EnableInput(GetWorld()->GetFirstPlayerController());

	this->PlayerCharacter = OtherActor;
}

// Signature for OnEndOverlap for SphereComponent
void AInventoryItemActor::OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{   // Disable PlayerController inputs
	DisableInput(GetWorld()->GetFirstPlayerController());

	this->PlayerCharacter = OtherActor;
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
