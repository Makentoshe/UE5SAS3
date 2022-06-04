// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Items/Items/Structures/FGameItemStructure.h>
#include "GameItemActorComponent.generated.h"

/* Component declares that owner actor have some knowledge about itself */
UCLASS(BlueprintType, Abstract, Blueprintable, meta=(BlueprintSpawnableComponent))
class SAS3_API UGameItemActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Default constructor
	UGameItemActorComponent();
		
	// Default virtual destructor
	virtual ~UGameItemActorComponent();

	// Contains general info about owner
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FGameItemStructure GameItem3;
};
