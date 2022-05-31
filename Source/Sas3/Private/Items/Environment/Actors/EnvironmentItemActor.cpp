// Fill out your copyright notice in the Description page of Project Settings.


#include <Sas3/Public/Items/Environment/Actors/EnvironmentItemActor.h>
#include <Sas3/Public/Feature/Feature_Interaction/Components/InteractorActorComponent.h>
#include <Sas3/Public/Feature/Feature_Interaction/Interfaces/InteractorActorComponentHolder.h>
#include <Sas3/Public/Items/Items/Actors/GameItemActor.h>
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AEnvironmentItemActor::AEnvironmentItemActor()
{
	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = false;
}

AEnvironmentItemActor::~AEnvironmentItemActor() {}

void AEnvironmentItemActor::BeginPlay()
{
	Super::BeginPlay();

	// Initialize OnNearbyInteractionBeginEvent delegate
	FName FNameNearbyInteractionBegin("OnNearbyInteractionBeginEvent");
	FScriptDelegate FScriptDelegateNearbyInteractionBegin;
	FScriptDelegateNearbyInteractionBegin.BindUFunction(this, FNameNearbyInteractionBegin);
	this->OnNearbyInteractionBegin.Add(FScriptDelegateNearbyInteractionBegin);

	// Initialize OnNearbyInteractionEndEvent delegate
	FName FNameNearbyInteractionEnd("OnNearbyInteractionEndEvent");
	FScriptDelegate FScriptDelegateNearbyInteractionEnd;
	FScriptDelegateNearbyInteractionEnd.BindUFunction(this, FNameNearbyInteractionEnd);
	this->OnNearbyInteractionEnd.Add(FScriptDelegateNearbyInteractionEnd);
}

void AEnvironmentItemActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	this->OnNearbyInteractionEnd.Clear();
	this->OnNearbyInteractionBegin.Clear();
}

void AEnvironmentItemActor::OnNearbyInteractionBeginEvent(AActor* OverlappedActor)
{   // If this item is enabled for the player - skip it
	if (!EnvironmentMeta.IsEnabled) return;
	// Check overlapped actor can interact with this item
	if (!OverlappedActor->GetClass()->ImplementsInterface(UInteractorActorComponentHolder::StaticClass())) {
		//if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "OverlappedActor doesn't implements UInteractorActorComponentHolder interface");
		return;
	}
	// Invoke InteractorActorComponent OnAddNearbyInteraction event
	auto InteractorActorComponent = IInteractorActorComponentHolder::Execute_GetInteractorActorComponent(OverlappedActor);
	InteractorActorComponent->AddNearbyInteractionStructure(BuildNearbyInteractionStructure());
}

void AEnvironmentItemActor::OnNearbyInteractionEndEvent(AActor* OverlappedActor)
{   // If this item is enabled for the player - skip it
	if (!EnvironmentMeta.IsEnabled) return;
	// Check overlapped actor can interact with this item
	if (!OverlappedActor->GetClass()->ImplementsInterface(UInteractorActorComponentHolder::StaticClass())) {
		//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "OverlappedActor doesn't implements UInteractorActorComponentHolder interface");
		return;
	}
	// Invoke InteractorActorComponent OnRemoveNearbyInteraction event
	auto InteractorActorComponent = IInteractorActorComponentHolder::Execute_GetInteractorActorComponent(OverlappedActor);
	InteractorActorComponent->RemoveNearbyInteractionStructure(BuildNearbyInteractionStructure());
}

// Create structure that will describe interaction
FNearbyInteractionStructure AEnvironmentItemActor::BuildNearbyInteractionStructure()
{
	FNearbyInteractionStructure NearbyInteractionStructure;
	NearbyInteractionStructure.Title = GameItem.Title;
	NearbyInteractionStructure.Description = EnvironmentMeta.Description;
	NearbyInteractionStructure.NearbyInteractionType = NearbyInteractionType::Environment;
	NearbyInteractionStructure.Actor = this;
	return NearbyInteractionStructure;
}
