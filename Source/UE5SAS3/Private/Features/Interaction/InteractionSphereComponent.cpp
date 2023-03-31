// Fill out your copyright notice in the Description page of Project Settings.

#include "Features/Interaction/InteractionSphereComponent.h"

#include "Kismet/GameplayStatics.h"

#include "Features/Interaction/InteractorComponent.h"
#include "Features/Interaction/InteractionSubsystem.h"


// Initializations

UInteractionSphereComponent::UInteractionSphereComponent()
{  
	// Set shape yellow collor for Unreal Editor
	this->ShapeColor = FColor::Yellow;
	// Enable interaction by default
	this->IsInteractionEnabled = true;
}

void UInteractionSphereComponent::OnRegister()
{
	Super::OnRegister();
	this->SetCollisionProfileName("Trigger");

	// Initialize OnBeginOverlap delegate
	FName FNameBeginOverlap("OnSphereComponentBeginOverlap");
	FScriptDelegate FScriptDelegateSphereComponentBeginOverlap;
	FScriptDelegateSphereComponentBeginOverlap.BindUFunction(this, FNameBeginOverlap);
	this->OnComponentBeginOverlap.AddUnique(FScriptDelegateSphereComponentBeginOverlap);

	// Initialize OnEndOverlap delegate
	FName FNameEndOverlap("OnSphereComponentEndOverlap");
	FScriptDelegate FScriptDelegateSphereComponentEndOverlap;
	FScriptDelegateSphereComponentEndOverlap.BindUFunction(this, FNameEndOverlap);
	this->OnComponentEndOverlap.AddUnique(FScriptDelegateSphereComponentEndOverlap);
}

void UInteractionSphereComponent::OnUnregister()
{
	Super::OnUnregister();

	this->OnComponentBeginOverlap.Clear();
	this->OnComponentEndOverlap.Clear();
}

UInteractionSphereComponent::~UInteractionSphereComponent()
{
}

// Collision events

void UInteractionSphereComponent::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{   // Check is interaction enabled for this component
	if (!this->IsInteractionEnabled) {
		return; // if not
	}

	// Our interactor actor should contain InteractorComponent
	// Check is overlapped component implements interactor component interface
	if (OtherComp->GetClass()->ImplementsInterface(UInteractorComponent::StaticClass())) {
		// Get game instance from world and check pointer is ok
		auto GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
		if (!GameInstance) return;
		// Add Interaction to Interactor via Subsystem
		auto InteractionSubsystem = GameInstance->GetSubsystem<UInteractionSubsystem>();
		InteractionSubsystem->AddInteractionToInteractor(this, OtherComp);
	}
}

void UInteractionSphereComponent::OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{   // Check is interaction enabled for this component
	if (!this->IsInteractionEnabled) {
		return; // if not
	}

	// Our interactor actor should contain InteractorComponent
	// Check is overlapped component implements interactor component interface
	if (OtherComp->GetClass()->ImplementsInterface(UInteractorComponent::StaticClass())) {
		// Get game instance from world and check pointer is ok
		auto GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
		if (!GameInstance) return;
		// Remove Interaction from Interactor via Subsystem
		auto InteractionSubsystem = GameInstance->GetSubsystem<UInteractionSubsystem>();
		InteractionSubsystem->RemoveInteractionFromInteractor(this, OtherComp);
	}
}

void UInteractionSphereComponent::OnInteractionComponentAvailable_Implementation()
{
	// If interaction already available: do nothing
	if (this->IsAvailable) return;

	// Mark component as available to interaction
	this->IsAvailable = true;

	// Send event if we want todo something in blueprints, for example
	this->OnInteractionComponentAvailableDelegate.Broadcast();
}

void UInteractionSphereComponent::OnInteractionComponentUnavailable_Implementation()
{
	// If interaction already unavailable: do nothing
	if (!this->IsAvailable) return;

	// Mark component as not available to interaction
	this->IsAvailable = false;
	// Component cant be selected if it is not avaialble
	this->IsSelected = false;

	// Send event if we want todo something in blueprints, for example
	this->OnInteractionComponentUnavailableDelegate.Broadcast();
}

void UInteractionSphereComponent::OnInteractionComponentSelected_Implementation()
{
	// If component already selected: do nothing
	if (this->IsSelected) return;

	// Mark component as selected
	this->IsSelected = true;
	// So, component also should be avaialble
	this->IsAvailable = true;

	// Send event if we want todo something in blueprints, for example
	this->OnInteractionComponentSelectedDelegate.Broadcast();
}

void UInteractionSphereComponent::OnInteractionComponentUnselected_Implementation()
{
	// If component already unselected: do nothing
	if (!this->IsSelected) return;

	// Mark component as unselected
	this->IsSelected = false;

	// Send event if we want todo something in blueprints, for example
	this->OnInteractionComponentUnselectedDelegate.Broadcast();
}

void UInteractionSphereComponent::OnInteractionComponentInteracted_Implementation(const TScriptInterface<IInteractorComponent>& InteractorComponent)
{
	// We can delegate this method to blueprints
	this->OnInteractionComponentInteractDelegate.Broadcast(InteractorComponent);
}
