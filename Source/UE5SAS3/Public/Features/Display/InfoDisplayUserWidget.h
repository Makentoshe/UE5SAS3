// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InfoDisplayUserWidget.generated.h"

/**
 * Widget for displaying a FSDisplayInfo structure for the player
 */
UCLASS(Abstract, BlueprintType, Category = "Display Feature")
class UE5SAS3_API UInfoDisplayUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Display Feature")
	FString LabelString;

	UPROPERTY(BlueprintReadWrite, Category = "Display Feature")
	FString DescriptionString;

public:

	FORCEINLINE FString GetLabelString() const { return LabelString; }
	void SetLabelString(FString String) { LabelString = String; }

	FORCEINLINE FString GetDescriptionString() const { return DescriptionString; }
	void SetDescriptionString(FString String) { DescriptionString = String; }
};
