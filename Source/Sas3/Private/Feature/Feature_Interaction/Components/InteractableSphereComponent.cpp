// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Interaction/Components/InteractableSphereComponent.h"
#include <Sas3/Public/Feature/Feature_Interaction/Components/InteractorActorComponent.h>
#include <Sas3/Public/Feature/Feature_Interaction/Interfaces/InteractorActorComponentHolder.h>
#include <Sas3/Public/Feature/Feature_Interaction/Structure/Wrapper/InteractionWrapper.h>


UInteractableSphereComponent::UInteractableSphereComponent()
{   // Set default interaction sphere radius to 128
	this->SphereRadius = 128.0f;
	// Set shape green collor for Unreal Editor
	this->ShapeColor = FColor::Green;


	this->SetCollisionProfileName("Trigger");

	// Initialize OnBeginOverlap delegate
	FName FNameBeginOverlap("OnSphereComponentBeginOverlap");
	FScriptDelegate FScriptDelegateSphereComponentBeginOverlap;
	FScriptDelegateSphereComponentBeginOverlap.BindUFunction(this, FNameBeginOverlap);
	this->OnComponentBeginOverlap.Add(FScriptDelegateSphereComponentBeginOverlap);

	// Initialize OnEndOverlap delegate
	FName FNameEndOverlap("OnSphereComponentEndOverlap");
	FScriptDelegate FScriptDelegateSphereComponentEndOverlap;
	FScriptDelegateSphereComponentEndOverlap.BindUFunction(this, FNameEndOverlap);
	this->OnComponentEndOverlap.Add(FScriptDelegateSphereComponentEndOverlap);
}

UInteractableSphereComponent::~UInteractableSphereComponent()
{
}

void UInteractableSphereComponent::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{   // Check overlapped actor can interact with this item
	if (!OtherActor->GetClass()->ImplementsInterface(UInteractorActorComponentHolder::StaticClass())) {
		//if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "OverlappedActor doesn't implements UInteractorActorComponentHolder interface");
		return;
	}

	auto InteractorActorComponent = IInteractorActorComponentHolder::Execute_GetInteractorActorComponent(OtherActor);
	InteractorActorComponent->AddInteractionWrapper(GetInteractionWrapper());
}

void UInteractableSphereComponent::OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{   // Check overlapped actor can interact with this item
	if (!OtherActor->GetClass()->ImplementsInterface(UInteractorActorComponentHolder::StaticClass())) {
		//if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "OverlappedActor doesn't implements UInteractorActorComponentHolder interface");
		return;
	}
	
	auto InteractorActorComponent = IInteractorActorComponentHolder::Execute_GetInteractorActorComponent(OtherActor);
	InteractorActorComponent->RemoveInteractionWrapper(GetInteractionWrapper());
}

UInteractionWrapper* UInteractableSphereComponent::GetInteractionWrapper()
{   // if InteractionWrapper already initialized just return it
	if (IsValid(this->InteractionWrapper)) return this->InteractionWrapper;
	// Create Wrapper from InteractionStructure
	auto Wrapper = NewObject<UInteractionWrapper>();
	Wrapper->InteractableActor = this->GetOwner();
	Wrapper->InteractionStructure = this->InteractionStructure;

	this->InteractionWrapper = Wrapper;
	return this->InteractionWrapper;
}
