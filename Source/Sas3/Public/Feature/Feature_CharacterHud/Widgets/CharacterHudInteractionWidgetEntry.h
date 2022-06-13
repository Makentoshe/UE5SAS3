// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Feature/Features/Widgets/BaseWidgetEntry.h"
#include "CharacterHudInteractionWidgetEntry.generated.h"

/**
 * A single element of the list of available interactions that player will see
 */
UCLASS(BlueprintType, Abstract)
class SAS3_API UCharacterHudInteractionWidgetEntry : public UBaseWidgetEntry
{
	GENERATED_BODY()
	
protected:

	/* Interaction title that player will see firstly */
	UPROPERTY(BlueprintReadWrite, Category = "Binding")
	FString ActionTitle;

	/* Additional interaction description that may make desicion clearer */
	UPROPERTY(BlueprintReadWrite, Category = "Binding")
	FString ActionDescription;

	/* Element background color allows to identify is this element selected or not */
	UPROPERTY(BlueprintReadWrite, Category = "Binding")
	FLinearColor ActionBackgroundColor;

	/* Element Foreground color allows to identify is this element selected or not */
	UPROPERTY(BlueprintReadWrite, Category = "Binding")
	FLinearColor ActionForegroundColor;
};
