// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class SAS3_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()

	protected:
	// Doing setup in the C++ constructor is not as useful as using NativeConstruct.
	virtual void NativeConstruct() override;

public:

	UPROPERTY(BlueprintReadOnly, Category = "CharacterHud | Interaction | Entry")
	FLinearColor CharacterHudInteractionEntrySelectedBackground;

	UPROPERTY(BlueprintReadOnly, Category = "CharacterHud | Interaction | Entry")
	FLinearColor CharacterHudInteractionEntrySelectedForeground;

	UPROPERTY(BlueprintReadOnly, Category = "CharacterHud | Interaction | Entry")
	FLinearColor CharacterHudInteractionEntryUnselectedBackground;

	UPROPERTY(BlueprintReadOnly, Category = "CharacterHud | Interaction | Entry")
	FLinearColor CharacterHudInteractionEntryUnselectedForeground;

	// Unopaque color for default selected item
	UPROPERTY(BlueprintReadOnly, Category="Background | Selection")
	FLinearColor SelectedBackground;

	// Unopaque color for default unselected item
	UPROPERTY(BlueprintReadOnly, Category = "Background | Selection")
	FLinearColor UnselectedBackground;

	// Opaque color for default selected item
	UPROPERTY(BlueprintReadOnly, Category = "Background | Selection")
	FLinearColor SelectedBackgroundOpaque;

	// Opaque color for default selected item
	UPROPERTY(BlueprintReadOnly, Category = "Background | Selection")
	FLinearColor UnselectedBackgroundOpaque;

	// Default opaque background
	UPROPERTY(BlueprintReadOnly, Category = "Background | Default")
	FLinearColor BackgroundOpaque;

	// Unopaque color for default selected item
	UPROPERTY(BlueprintReadOnly, Category = "Foreground | Selection")
	FLinearColor SelectedForeground;

	// Unopaque color for default unselected item
	UPROPERTY(BlueprintReadOnly, Category = "Foreground | Selection")
	FLinearColor UnselectedForeground;

	// Opaque color for default selected item
	UPROPERTY(BlueprintReadOnly, Category = "Foreground | Selection")
	FLinearColor SelectedForegroundOpaque;

	// Opaque color for default selected item
	UPROPERTY(BlueprintReadOnly, Category = "Foreground | Selection")
	FLinearColor UnselectedForegroundOpaque;

};
