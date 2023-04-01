// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Saveload/SaveloadSubsystem.h"

void USaveloadSubsystem::SaveGameToSlot()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("SaveGame"));
}

void USaveloadSubsystem::LoadGameFromSlot()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("LoadGame"));
}
