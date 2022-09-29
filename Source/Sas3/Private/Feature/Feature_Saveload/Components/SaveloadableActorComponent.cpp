// Fill out your copyright notice in the Description page of Project Settings.

#include "Serialization/ObjectAndNameAsStringProxyArchive.h"

#include <Sas3/Public/Feature/Feature_Inventory/Components/InventorableActorComponent.h>
#include <Sas3/Public/Feature/Feature_Saveload/Objects/InventorableComponentSaveloadWrapper.h>

#include "Feature/Feature_Saveload/Components/SaveloadableActorComponent.h"

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

	//// Write InventorableComponent
	//auto InventorableComponent = GetOwner()->FindComponentByClass<UInventorableActorComponent>();
	//if (IsValid(InventorableComponent)) {
	//	UInventorableComponentSaveloadWrapper* InventorableComponentWrapper = NewObject<UInventorableComponentSaveloadWrapper>();
	//	InventorableComponentWrapper->ItemCount = InventorableComponent->InventoryMeta.ItemCount;
	//	InventorableComponentWrapper->StackSize = InventorableComponent->InventoryMeta.StackSize;
	//	SaveloadActorStructure.InventorableComponentWrapper = InventorableComponentWrapper;
	//}

	// Prepare to actor serialization
	FMemoryWriter MemoryWriter(SaveloadActorStructure.ByteData);
	FObjectAndNameAsStringProxyArchive Archive(MemoryWriter, true);
	//Archive.ArIsSaveGame = true; // Find only variables with UPROPERTY(SaveGame)
	// Serialize owner actor
	GetOwner()->Serialize(Archive);

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

	// Prepare for actor deserialization
	FMemoryReader MemoryReader(Structure.ByteData);
	FObjectAndNameAsStringProxyArchive Archive(MemoryReader, true);
	//Archive.ArIsSaveGame = true;
	// Deserialize actor
	GetOwner()->Serialize(Archive);

	// Notify that deserialization was performed
	this->OnActorDeserialized.Broadcast(Structure);
}
