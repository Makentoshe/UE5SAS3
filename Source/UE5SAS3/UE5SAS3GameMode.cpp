// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5SAS3GameMode.h"
#include "UE5SAS3Character.h"
#include "UObject/ConstructorHelpers.h"

AUE5SAS3GameMode::AUE5SAS3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
