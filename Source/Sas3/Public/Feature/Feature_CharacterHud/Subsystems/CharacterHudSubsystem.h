// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "CharacterHudSubsystem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SAS3_API UCharacterHudSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:

    // Begin USubsystem
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    // End USubsystem
    //virtual void Deinitialize() override;
    
    
	
};
