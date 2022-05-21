// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/AThirdPersonPlayerController.h"
#include "Framework/Application/NavigationConfig.h"

void AThirdPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// Check we are in a single play
	if (IsLocalPlayerController()) { 
		TSharedRef<FNavigationConfig> Navigation = MakeShared<FNavigationConfig>();
		Navigation->bKeyNavigation = false; // disable arrows button
		Navigation->bTabNavigation = false; // disable tab button
		//Navigation->bAnalogNavigation = false;
		FSlateApplication::Get().SetNavigationConfig(Navigation);
	} else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Error: Not LocalPlayerController"));
	}
}
