// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LabelDisplayUserWidget.generated.h"

/**
 * Widget for displaying a FSDisplayLabel structure for the player
 */
UCLASS(Abstract, BlueprintType, Category = "Display Feature")
class UE5SAS3_API ULabelDisplayUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected: 
	UPROPERTY(BlueprintReadWrite, Category = "Display Feature")
	FString LabelText;
	
public:
	
	FORCEINLINE FString GetLabelString() const { return LabelText; }
	void SetLabelString(FString String) { LabelText = String; }
};
