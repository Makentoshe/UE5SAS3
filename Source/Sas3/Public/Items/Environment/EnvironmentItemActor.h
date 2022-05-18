// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/GameItemActor.h"
#include "GameFramework/Actor.h"
#include "EnvironmentItemActor.generated.h"

/**
 * Player may interact with this actor
 * TODO: not finished yet
 */
UCLASS(BlueprintType)
class SAS3_API AEnvironmentItemActor : public AGameItemActor
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	// Called when selected actor overlaps interaction collision
	UFUNCTION()
	void OnNearbyInteractionEndEvent(AActor* OverlappedActor);

	// Called when selected actor overlaps interaction collision
	UFUNCTION()
	void OnNearbyInteractionBeginEvent(AActor* OverlappedActor);
};
