// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Interaction/Components/InteractableSphereComponent.h"


UInteractableSphereComponent::UInteractableSphereComponent()
{   // Set default interaction sphere radius to 128
	this->SphereRadius = 128.0f;
	// Set shape green collor for Unreal Editor
	this->ShapeColor = FColor::Green;
	// Enable interaction by default
	this->IsInteractionEnabled = true;
}

void UInteractableSphereComponent::OnRegister()
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

void UInteractableSphereComponent::OnUnregister()
{
	Super::OnUnregister();

	this->OnComponentBeginOverlap.Clear();
	this->OnComponentEndOverlap.Clear();
}

UInteractableSphereComponent::~UInteractableSphereComponent()
{
}



void UInteractableSphereComponent::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{   // Check is interaction enabled for this component
	if (!this->IsInteractionEnabled) {
		return; // if not
	}

	this->OnAddInteractionWrapper.Broadcast(OtherActor, this->InteractionStructure);
}

void UInteractableSphereComponent::OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{   // Check is interaction enabled for this component
	if (!this->IsInteractionEnabled) {
		return; // if not
	}
	
	this->OnRemoveInteractionWrapper.Broadcast(OtherActor, this->InteractionStructure);
}

void UInteractableSphereComponent::SelectInteractableOwner(AActor* InteractedActor, bool SelectionValue)
{
	this->OnInteractionSelectedChanged.Broadcast(InteractedActor, SelectionValue);
}

void UInteractableSphereComponent::InitializeInteraction()
{
	this->OnInteractionStarted.Broadcast();
}

void UInteractableSphereComponent::FinalizeInteraction()
{
	this->OnInteractionFinished.Broadcast();
}
