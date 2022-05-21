// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AThirdPersonPlayerController.generated.h"

/**
 * Custom PlayerController for a third person character
 */
UCLASS()
class SAS3_API AThirdPersonPlayerController : public APlayerController
{
	GENERATED_BODY()

	void BeginPlay() override;
};
