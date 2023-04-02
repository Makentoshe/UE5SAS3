// Fill out your copyright notice in the Description page of Project Settings.

#include "Features/Saveload/SaveloadSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "EngineUtils.h"

#include "Features/Saveload/SaveloadComponentHolder.h"
#include "Features/Saveload/UE5SAS3SaveGame.h"

void USaveloadSubsystem::SaveGameToSlot()
{	// Create an instance of the SaveGame class
	UUE5SAS3SaveGame *SaveGameInstance = Cast<UUE5SAS3SaveGame>(UGameplayStatics::CreateSaveGameObject(UUE5SAS3SaveGame::StaticClass()));

	// Invoke SaveGameStarted broadcast
	OnSaveGameStarted.Broadcast();

	// Iterate though all actors in the world
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{  	// Follow iterator object to actual actor pointer
		AActor* Actor = *ActorItr;

		// Skip all actors that are null or being destroyed or garbage collected
		if (!IsValid(Actor)) continue;
		// We interested only in entities that contains SaveloadableComponent.
		if (!Actor->GetClass()->ImplementsInterface(USaveloadComponentHolder::StaticClass())) {
			continue; //if not
		}

		// Get SaveloadComponent from SaveloadComponentHolder interface
		TScriptInterface<ISaveloadComponent> SaveloadComponent;
		ISaveloadComponentHolder::Execute_GetSaveloadComponent(Actor, SaveloadComponent);
		if (!IsValid(SaveloadComponent.GetObject())) continue; // interface doesn't provide any value

		// Serialize component owner to SaveloadObject
		FSSaveloadObject SaveloadObject = FSSaveloadObject();
		SaveloadComponent->Execute_Serialize(SaveloadComponent.GetObject(), SaveloadObject);
		// Put SaveloadObject to SaveGameInstance
		FName Identifier = SaveloadComponent->Execute_GetOwnerActor(SaveloadComponent.GetObject())->GetFName();
		SaveGameInstance->AddSaveloadObject(Identifier, SaveloadObject);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Identifier.ToString());
	}

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Slot"), 0);

	// Invoke SaveGameCompleted broadcast
	OnSaveGameCompleted.Broadcast();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("SaveGame"));
}

void USaveloadSubsystem::LoadGameFromSlot()
{
	// Get an instance of the SaveGame class
	UUE5SAS3SaveGame* SaveGameInstance = Cast<UUE5SAS3SaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Slot"), 0));

	// Invoke LoadGameStarted broadcast
	OnLoadGameStarted.Broadcast();

	// Iterate though all actors in the world
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{  	// Follow iterator object to actual actor pointer
		AActor* Actor = *ActorItr;

		// Skip all actors that are null or being destroyed or garbage collected
		if (!IsValid(Actor)) continue;
		// We interested only in entities that contains SaveloadableComponent.
		if (!Actor->GetClass()->ImplementsInterface(USaveloadComponentHolder::StaticClass())) {
			continue; //if not
		}

		// Get SaveloadComponent from SaveloadComponentHolder interface
		TScriptInterface<ISaveloadComponent> SaveloadComponent;
		ISaveloadComponentHolder::Execute_GetSaveloadComponent(Actor, SaveloadComponent);
		if (!IsValid(SaveloadComponent.GetObject())) continue; // interface doesn't provide any value
		// Get Identifier which helps to find correct object
		FName Identifier = SaveloadComponent->Execute_GetOwnerActor(SaveloadComponent.GetObject())->GetFName();
		FSSaveloadObject SaveloadObject = SaveGameInstance->GetSaveloadObject(Identifier);

		// Deserialize 
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Identifier.ToString());
		SaveloadComponent->Execute_Deserialize(SaveloadComponent.GetObject(), SaveloadObject);
	}

	// Invoke LoadGameCompleted broadcast
	OnLoadGameCompleted.Broadcast();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("LoadGame"));

}
