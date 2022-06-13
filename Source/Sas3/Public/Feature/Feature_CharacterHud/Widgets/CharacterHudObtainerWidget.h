// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Feature/Features/Widgets/BaseWidget.h"
#include "CharacterHudObtainerWidget.generated.h"

/**
 * Widget that displays obtained items on the screen during gameplay
 */
UCLASS(BlueprintType, Abstract)
class SAS3_API UCharacterHudObtainerWidget : public UBaseWidget
{
	GENERATED_BODY()

protected:
	// Widget to use to display last obtained items
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<class UListView> ObtainingsContainer;
};
