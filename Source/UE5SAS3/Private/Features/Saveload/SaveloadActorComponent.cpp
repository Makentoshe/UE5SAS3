// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Saveload/SaveloadActorComponent.h"
#include "Features/Feature/Interface/UE5SAS3FollowCameraHolder.h"


// Sets default values for this component's properties
USaveloadActorComponent::USaveloadActorComponent()
{	// Set this component to be initialized when the game starts, and to be ticked every frame. 
	PrimaryComponentTick.bCanEverTick = false;
}

void USaveloadActorComponent::Serialize_Implementation(FSSaveloadObject& SaveloadObject)
{	// Invoke serialize callback
	OnSerializeDelegate.Broadcast(SaveloadObject);
	
	// Set actor general state (possibly destroyed or not)
	SaveloadObject.IsActorDestroyed = !IsValid(GetOwner()) || GetOwner()->IsHidden();

	// Save owner actor transform
	SaveloadObject.ActorTransform = GetOwner()->GetActorTransform();

}

void USaveloadActorComponent::Deserialize_Implementation(const FSSaveloadObject& SaveloadObject)
{	// Invoke deserialize callback
	OnDeserializeDelegate.Broadcast(SaveloadObject);

	// If actor is marked as hidden(destroyed)
	if (SaveloadObject.IsActorDestroyed) {
		GetOwner()->Destroy();
		return;
	}

	// Show actor on the scene
	GetOwner()->SetActorHiddenInGame(false);
	
	// Restore owner actor transform
	GetOwner()->SetActorTransform(SaveloadObject.ActorTransform);
}

AActor* USaveloadActorComponent::GetOwnerActor_Implementation()
{	// Restore owner actor transform
	return GetOwner();
}