// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/InventoryItemActor.h"

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

	// Define item pickup action and disable input by default
	GetWorld()->GetFirstPlayerController()->InputComponent->BindKey(EKeys::E, IE_Pressed, this, &AInventoryItemActor::OnItemPickupAction);
	GetWorld()->GetFirstPlayerController()->DisableInput(GetWorld()->GetFirstPlayerController());
}

// Called every frame
void AInventoryItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Signature for OnBeginOverlap for SphereComponent
void AInventoryItemActor::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	auto message = FString::Printf(TEXT("OnBeginOverlap"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, message);
	PlayerCharacter = OtherActor;

	// Enable PlayerController inputs
	GetWorld()->GetFirstPlayerController()->EnableInput(GetWorld()->GetFirstPlayerController());
}

// Signature for OnEndOverlap for SphereComponent
void AInventoryItemActor::OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto message = FString::Printf(TEXT("OnEndOverlap"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, message);
	PlayerCharacter = OtherActor;

	// Disable PlayerController inputs
	GetWorld()->GetFirstPlayerController()->DisableInput(GetWorld()->GetFirstPlayerController());
}

// Signature for OnKeyEventPressed(E)
void AInventoryItemActor::OnItemPickupAction() {
	//PlayerCharacter->GetClass()->ImplementsInterface()
	//bool bIsImplemented = GetWorld()->GetPlayerC

	auto message = FString::Printf(TEXT("ItemPickup"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, message);
}
