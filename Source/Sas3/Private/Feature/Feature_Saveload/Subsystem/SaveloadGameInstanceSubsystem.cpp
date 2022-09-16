// Fill out your copyright notice in the Description page of Project Settings.



#include "EngineUtils.h"
#include "Engine.h"

#include "Feature/Feature_Saveload/Subsystem/SaveloadGameInstanceSubsystem.h"
#include <Sas3/Public/Feature/Feature_Saveload/SaveGameGeneral.h>
#include <Sas3/Public/Feature/Feature_Saveload/Interfaces/SaveloadableActorComponentHolder.h>


void USaveloadGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{   // Default unitialized structure
	this->CurrentGeneralSaveloadSlot = FSaveloadSlotStructure();
}

void USaveloadGameInstanceSubsystem::Deinitialize()
{	// Clear callbacks
	this->OnGeneralSaveGameInstanceCreated.Clear();
	this->OnActorSerialized.Clear();
	this->OnAsyncSaveGameCompleted.Clear();
	this->OnAsyncSaveGameStarted.Clear();
}

FSaveloadSlotStructure USaveloadGameInstanceSubsystem::GetCurrentGeneralSaveloadSlot()
{
	return this->CurrentGeneralSaveloadSlot;
}

void USaveloadGameInstanceSubsystem::SetCurrentGeneralSaveloadSlot(FSaveloadSlotStructure structure)
{
	this->CurrentGeneralSaveloadSlot = structure;
}

void USaveloadGameInstanceSubsystem::CreateCurrentGeneralSaveload(FString SaveGameSlotTitle)
{
	this->CurrentGeneralSaveloadSlot = FSaveloadSlotStructure(SaveGameSlotTitle);
}

void USaveloadGameInstanceSubsystem::SaveCurrentGeneralSaveloadSlot()
{	// Get current general saveload slot
	auto GeneralSaveloadSlot = GetCurrentGeneralSaveloadSlot();	
	// Create SaveGameInstance
	auto StaticClass = USaveGameGeneral::StaticClass();
	auto SaveGameObject = UGameplayStatics::CreateSaveGameObject(StaticClass);
	auto SaveGameInstance = Cast<USaveGameGeneral>(SaveGameObject);
	// Notify that GeneralSaveGame instance was created
	this->OnGeneralSaveGameInstanceCreated.Broadcast(SaveGameInstance);
	// Iterate over all actors
	for (TActorIterator<AActor> Iterator(GetWorld()); Iterator; ++Iterator)
	{	// Follow iterator object to actual actor pointer
		AActor* Actor = *Iterator;
		// Skip all actors that are null or being destroyed or garbage collected
		if (!IsValid(Actor)) continue;
		// We interested only in entities that contains SaveloadableComponent.
		if (!Actor->GetClass()->ImplementsInterface(USaveloadableActorComponentHolder::StaticClass())) {
			continue; //if not
		}
		auto SaveloadableComponent = ISaveloadableActorComponentHolder::Execute_GetSaveloadableActorComponent(Actor);
		if (!IsValid(SaveloadableComponent)) return; // interface doesn't provide any value
		// Serialized actor's structure
		auto Structure = SaveloadableComponent->GetSaveloadActorStructure();
		SaveGameInstance->AddSerializedActor(Structure);
		// Notify that selected Actor was serialized into Structure
		this->OnActorSerialized.Broadcast(Actor, Structure);
	}
	// Initialize callback
	auto AsyncSaveDelegate = FAsyncSaveGameToSlotDelegate();
	AsyncSaveDelegate.BindUFunction(this, "OnAsyncSaveGame");
	// Perform async savegame
	UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, GeneralSaveloadSlot.Filename, 0, AsyncSaveDelegate);
	// Notify that async savegame process began
	this->OnAsyncSaveGameStarted.Broadcast(CurrentGeneralSaveloadSlot, SaveGameInstance);
}

void USaveloadGameInstanceSubsystem::LoadCurrentGeneralSaveloadSlot()
{	// Get current general saveload slot
	auto GeneralSaveloadSlot = GetCurrentGeneralSaveloadSlot();
	// Check current general saveload slot exists
	if (!UGameplayStatics::DoesSaveGameExist(GeneralSaveloadSlot.Filename, 0)) {
		return; //if not
	}

	// Initialize callback
	auto AsyncLoadDelegate = FAsyncLoadGameFromSlotDelegate();
	AsyncLoadDelegate.BindUFunction(this, "OnAsyncLoadGame");
	// Perform async loading
	UGameplayStatics::AsyncLoadGameFromSlot(GeneralSaveloadSlot.Filename, 0, AsyncLoadDelegate);
	// Notify that async loadgame process began
	this->OnAsyncLoadGameStarted.Broadcast(GeneralSaveloadSlot);
}

void USaveloadGameInstanceSubsystem::OnAsyncSaveGame(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	this->OnAsyncSaveGameCompleted.Broadcast(SlotName, UserIndex, bSuccess);
}

void USaveloadGameInstanceSubsystem::OnAsyncLoadGame(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData)
{   // return if save is not our type. (wtf, this must be an error)
	if (!LoadedGameData->IsA(USaveGameGeneral::StaticClass())) return;
	auto LoadGameInstance = Cast<USaveGameGeneral>(LoadedGameData);
	// Complexity O(n^2). Each actor will be notified about each deserialization
	for (FSaveloadActorStructure Structure : LoadGameInstance->GetSerializedActors()) {
		// Notify that actor was deserialized
		this->OnActorDeserialized.Broadcast(Structure);
	}
	// Notify that async loadgame process was finish
	this->OnAsyncLoadGameCompleted.Broadcast(LoadGameInstance);
}
