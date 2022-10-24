// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Saveload/Components/SaveloadableActorComponent.h"

#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "JsonObjectConverter.h"


#include <Sas3/Public/Feature/Feature_Inventory/Components/InventorableActorComponent.h>
#include <Sas3/Public/Feature/Feature_Interaction/Components/InteractableSphereComponent.h>

// Sets default values for this component's properties
USaveloadableActorComponent::USaveloadableActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FSaveloadActorStructure USaveloadableActorComponent::GetSaveloadActorStructure()
{   // Generate SaveloadJsonStructure
	FSaveloadJsonStructure SaveloadJsonStructure;

	// Serialize InventorableComponent
	auto InventorableComponent = GetOwner()->FindComponentByClass<UInventorableActorComponent>();
	if (IsValid(InventorableComponent)) { // check is we have InventorableComponent
		SaveloadJsonStructure.InventorableComponentItemCount = InventorableComponent->InventoryMeta.ItemCount;
		SaveloadJsonStructure.InventorableComponentStackSize = InventorableComponent->InventoryMeta.StackSize;
	}

	// Serialize InventoryComponent
	auto InventoryComponent = GetOwner()->FindComponentByClass<UInventoryActorComponent>();
	if (IsValid(InventoryComponent)) { // check is we have InventoryComponent
		SaveloadJsonStructure.InventoryComponentInventorySize = InventoryComponent->InventorySize;
		SaveloadJsonStructure.InventoryComponentInventoryItems = InventoryComponent->GetInventoryItems();
	}

	// Serialize Structure to JSON Object string
	FString SerializedSaveloadJsonStructure;
	FJsonObjectConverter::UStructToJsonObjectString(SaveloadJsonStructure, SerializedSaveloadJsonStructure);
	
	// Generate SaveloadActorStructure
	FSaveloadActorStructure SaveloadActorStructure;
	SaveloadActorStructure.ActorIdentifier = GetOwner()->GetFName();
	SaveloadActorStructure.Transform = GetOwner()->GetActorTransform();
	SaveloadActorStructure.SerializedData = SerializedSaveloadJsonStructure;

	//Notify that serialization was performed
	this->OnActorSerialized.Broadcast(SaveloadActorStructure, SaveloadJsonStructure);

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
	//Deserialize JSON Object string
	FSaveloadJsonStructure SaveloadJsonStructure;
	if (!FJsonObjectConverter::JsonObjectStringToUStruct(Structure.SerializedData, &SaveloadJsonStructure, 0, 0))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Error"));
		return;
	}

	// Deserialize InventorableComponent
	auto InventorableComponent = GetOwner()->FindComponentByClass<UInventorableActorComponent>();
	if (IsValid(InventorableComponent)) { // check is we have InventorableComponent
		InventorableComponent->InventoryMeta = {
			SaveloadJsonStructure.InventorableComponentItemCount,
			SaveloadJsonStructure.InventorableComponentStackSize,
		};
	}

	// Deserialize InventoryComponent
	auto InventoryComponent = GetOwner()->FindComponentByClass<UInventoryActorComponent>();
	if (IsValid(InventoryComponent)) { // check is we have InventoryComponent
		InventoryComponent->InventorySize = SaveloadJsonStructure.InventoryComponentInventorySize;
		InventoryComponent->SetInventoryItems(SaveloadJsonStructure.InventoryComponentInventoryItems);
	}

	// Notify that deserialization was performed
	this->OnActorDeserialized.Broadcast(Structure, SaveloadJsonStructure);
}
