// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Saveload/Components/SaveloadableActorComponent.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventorableActorComponent.h>
#include <Sas3/Public/Feature/Feature_Interaction/Components/InteractableSphereComponent.h>

// Sets default values for this component's properties
USaveloadableActorComponent::USaveloadableActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FSaveloadActorStructure USaveloadableActorComponent::GetSaveloadActorStructure()
{   // Generate SaveloadActorStructure
	FSaveloadActorStructure SaveloadActorStructure;
	SaveloadActorStructure.ActorIdentifier = GetOwner()->GetFName();
	SaveloadActorStructure.Transform = GetOwner()->GetActorTransform();

	// Serialize InventorableComponent
	auto InventorableComponent = GetOwner()->FindComponentByClass<UInventorableActorComponent>();
	if (IsValid(InventorableComponent)) { // check is we have InventorableComponent
		SaveloadActorStructure.InventorableComponentSaveload.ItemCount = InventorableComponent->InventoryMeta.ItemCount;
		SaveloadActorStructure.InventorableComponentSaveload.StackSize = InventorableComponent->InventoryMeta.StackSize;
	}

	//Notify that serialization was performed
	this->OnActorSerialized.Broadcast(SaveloadActorStructure);

	return SaveloadActorStructure;
}

FName USaveloadableActorComponent::GetSaveloadActorIdentifier()
{
	return GetOwner()->GetFName();
}

void USaveloadableActorComponent::ConsumeSaveloadActorStructure(FSaveloadActorStructure Structure)
{   // Return if it is not our actor.
	if (GetSaveloadActorIdentifier() != Structure.ActorIdentifier) return;
	// Restore actor transform
	GetOwner()->SetActorTransform(Structure.Transform);

	// Deserialize InventorableComponent
	auto InventorableComponent = GetOwner()->FindComponentByClass<UInventorableActorComponent>();
	if (IsValid(InventorableComponent)) { // check is we have InventorableComponent
		InventorableComponent->InventoryMeta = {
			Structure.InventorableComponentSaveload.ItemCount,
			Structure.InventorableComponentSaveload.StackSize
		};
	}

	// Notify that deserialization was performed
	this->OnActorDeserialized.Broadcast(Structure);
}
