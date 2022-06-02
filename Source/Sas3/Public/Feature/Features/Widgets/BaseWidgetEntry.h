// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Feature/Features/Widgets/BaseWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "BaseWidgetEntry.generated.h"

/**
 * Base Entry for any ListView
 */
UCLASS(BlueprintType)
class SAS3_API UBaseWidgetEntry : public UBaseWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
};
