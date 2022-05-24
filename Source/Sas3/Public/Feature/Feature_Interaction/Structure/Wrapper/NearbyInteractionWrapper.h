// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Sas3/Public/Feature/Feature_Interaction/Structure/FNearbyInteractionStructure.h>
#include "NearbyInteractionWrapper.generated.h"

UCLASS(Blueprintable)
class SAS3_API UNearbyInteractionWrapper : public UObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UNearbyInteractionWrapper();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FNearbyInteractionStructure NearbyInteractionStructure;
};
