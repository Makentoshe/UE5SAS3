// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sas3GameMode.h"
#include "Sas3Character.h"
#include "UObject/ConstructorHelpers.h"

ASas3GameMode::ASas3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
