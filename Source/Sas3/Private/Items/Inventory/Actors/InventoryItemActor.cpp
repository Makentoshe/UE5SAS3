// Fill out your copyright notice in the Description page of Project Settings.


#include <Sas3/Public/Items/Inventory/Actors/InventoryItemActor.h>
#include <Sas3/Public/Feature/Feature_Interaction/Components/InteractorActorComponent.h>
#include <Sas3/Public/Feature/Feature_Interaction/Interfaces/InteractorActorComponentHolder.h>
#include <Sas3/Public/Items/Items/Actors/GameItemActor.h>

// Sets default values
AInventoryItemActor::AInventoryItemActor()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = false;
}

AInventoryItemActor::~AInventoryItemActor()
{
}

void AInventoryItemActor::BeginPlay()
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

void AInventoryItemActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	this->OnNearbyInteractionEnd.Clear();
	this->OnNearbyInteractionBegin.Clear();
}

void AInventoryItemActor::OnNearbyInteractionBeginEvent(AActor* OverlappedActor)
{   // Check overlapped actor can interact with this item
	if (!OverlappedActor->GetClass()->ImplementsInterface(UInteractorActorComponentHolder::StaticClass())) {
		//if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "OverlappedActor doesn't implements UInteractorActorComponentHolder interface");
		return;
	}
	// Invoke InteractorActorComponent OnAddNearbyInteraction event
	auto InteractorActorComponent = IInteractorActorComponentHolder::Execute_GetInteractorActorComponent(OverlappedActor);
	InteractorActorComponent->OnAddNearbyInteraction.Broadcast(BuildNearbyInteractionStructure());
}

void AInventoryItemActor::OnNearbyInteractionEndEvent(AActor* OverlappedActor)
{   // Check overlapped actor can interact with this item
	if (!OverlappedActor->GetClass()->ImplementsInterface(UInteractorActorComponentHolder::StaticClass())) {
		//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "OverlappedActor doesn't implements UInteractorActorComponentHolder interface");
		return;
	}
	// Invoke InteractorActorComponent OnRemoveNearbyInteraction event
	auto InteractorActorComponent = IInteractorActorComponentHolder::Execute_GetInteractorActorComponent(OverlappedActor);
	InteractorActorComponent->OnRemoveNearbyInteraction.Broadcast(BuildNearbyInteractionStructure());
}

// Create structure that will describe interaction
FNearbyInteractionStructure AInventoryItemActor::BuildNearbyInteractionStructure()
{
	FNearbyInteractionStructure NearbyInteractionStructure;
	NearbyInteractionStructure.Title = GameItem.Title;
	NearbyInteractionStructure.Description = FName(FString::FromInt(InventoryMeta.ItemCount));
	NearbyInteractionStructure.NearbyInteractionType = NearbyInteractionType::Inventory;
	NearbyInteractionStructure.Actor = this;
	return NearbyInteractionStructure;
}
