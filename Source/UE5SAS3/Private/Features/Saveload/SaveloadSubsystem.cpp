// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "Features/Saveload/SaveloadSubsystem.h"
#include "Features/Saveload/UE5SAS3SaveGame.h"

void USaveloadSubsystem::SaveGameToSlot()
{
	// Create an instance of the SaveGame class
	UUE5SAS3SaveGame *SaveGameInstance = Cast<UUE5SAS3SaveGame>(UGameplayStatics::CreateSaveGameObject(UUE5SAS3SaveGame::StaticClass()));
	// Set all variables to save
	ACharacter *PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	SaveGameInstance->PlayerLocation = PlayerCharacter->GetActorLocation();

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Slot"), 0);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("SaveGame"));
}

void USaveloadSubsystem::LoadGameFromSlot()
{
	UUE5SAS3SaveGame* SaveGameInstance = Cast<UUE5SAS3SaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Slot"), 0));

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	PlayerCharacter->SetActorLocation(SaveGameInstance->PlayerLocation);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("LoadGame"));

}
