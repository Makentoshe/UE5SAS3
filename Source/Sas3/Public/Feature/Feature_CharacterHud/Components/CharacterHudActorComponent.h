// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterHudActorComponent.generated.h"


UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UCharacterHudActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Default constructor
	UCharacterHudActorComponent();

protected:
	// Called when a component is registered, after Scene is set, but before CreateRenderState_Concurrent or OnCreatePhysicsState are called.
	virtual void OnRegister() override;

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called when a component is unregistered. Called after DestroyRenderState_Concurrent and OnDestroyPhysicsState are called.
	virtual void OnUnregister() override;



protected:
	// Reference to the owners controller
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<APlayerController> OwnerController;

	// Reference to the owner
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<APawn> OwnerPawn;
};
