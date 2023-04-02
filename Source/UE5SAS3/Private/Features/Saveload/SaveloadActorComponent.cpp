// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Saveload/SaveloadActorComponent.h"

// Sets default values for this component's properties
USaveloadActorComponent::USaveloadActorComponent()
{	// Set this component to be initialized when the game starts, and to be ticked every frame. 
	PrimaryComponentTick.bCanEverTick = false;
}

void USaveloadActorComponent::Serialize_Implementation(FSSaveloadObject& SaveloadObject)
{	// Save owner actor transform
	SaveloadObject.ActorTransform = GetOwner()->GetActorTransform();
}

void USaveloadActorComponent::Deserialize_Implementation(const FSSaveloadObject& SaveloadObject)
{	// Restore owner actor transform
	GetOwner()->SetActorTransform(SaveloadObject.ActorTransform);
}

AActor* USaveloadActorComponent::GetOwnerActor_Implementation()
{	// Restore owner actor transform
	return GetOwner();
}