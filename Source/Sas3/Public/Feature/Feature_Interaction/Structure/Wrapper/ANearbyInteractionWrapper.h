// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FNearbyInteractionStructure.h>
#include "ANearbyInteractionWrapper.generated.h"

UCLASS()
class SAS3_API AANearbyInteractionWrapper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AANearbyInteractionWrapper();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FNearbyInteractionStructure NearbyInteractionStructure;
};
