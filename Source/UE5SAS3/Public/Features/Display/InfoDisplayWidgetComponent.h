// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Features/Display/DisplayWidgetComponent.h"

#include "Features/Display/FSDisplayInfo.h"

#include "InfoDisplayWidgetComponent.generated.h"

/**
 * Component which holds and controls InfoDisplayUserWidget
 */
UCLASS(Blueprintable, BlueprintType, Category = "Display Feature")
class UE5SAS3_API UInfoDisplayWidgetComponent : public UDisplayWidgetComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Display Feature")
	void ShowDisplayWidget(const FSDisplayInfo Structure);
};
