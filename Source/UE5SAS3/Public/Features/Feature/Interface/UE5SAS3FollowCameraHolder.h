// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "UE5SAS3FollowCameraHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUE5SAS3FollowCameraHolder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE5SAS3_API IUE5SAS3FollowCameraHolder
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	UCameraComponent* GetFollowCameraComponent();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	USpringArmComponent* GetCameraBoomComponent();

};
