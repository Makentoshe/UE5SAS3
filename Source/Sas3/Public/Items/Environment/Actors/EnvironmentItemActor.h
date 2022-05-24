// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FNearbyInteractionStructure.h>
#include <Sas3/Public/Items/Environment/Structures/FEnvironmentMetaStructure.h>
#include <Sas3/Public/Items/Items/Actors/GameItemActor.h>
#include "EnvironmentItemActor.generated.h"

/**
 * Player may interact with this actor
 */
UCLASS(BlueprintType)
class SAS3_API AEnvironmentItemActor : public AGameItemActor
{
	GENERATED_BODY()
public: 
	AEnvironmentItemActor();

	virtual ~AEnvironmentItemActor();

protected:

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	// Called when selected actor overlaps interaction collision
	UFUNCTION()
	void OnNearbyInteractionEndEvent(AActor* OverlappedActor);

	// Called when selected actor overlaps interaction collision
	UFUNCTION()
	void OnNearbyInteractionBeginEvent(AActor* OverlappedActor);

	// Creates a NearbyInteractionStructure
	UFUNCTION()// TODO make a FNearbyInteractionStructure ptr with lazy init
	FNearbyInteractionStructure BuildNearbyInteractionStructure();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FEnvironmentMetaStructure EnvironmentMeta;
};
