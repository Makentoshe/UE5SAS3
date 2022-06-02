// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Feature/Features/Widgets/BaseWidgetEntry.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CharacterHudObtainerWidgetEntry.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract)
class SAS3_API UCharacterHudObtainerWidgetEntry : public UBaseWidgetEntry
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadWrite)
	FString ObtainedItemTitle;
	
};
