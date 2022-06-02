// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Features/Widgets/BaseWidget.h"

void UBaseWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Background | Selection
	this->SelectedBackground = FLinearColor::FromSRGBColor(FColor::FromHex("595959FF"));
	this->UnselectedBackground = FLinearColor::FromSRGBColor(FColor::FromHex("FFFFFFFF"));
	this->SelectedBackgroundOpaque = FLinearColor::FromSRGBColor(FColor::FromHex("59595980"));
	this->UnselectedBackgroundOpaque = FLinearColor::FromSRGBColor(FColor::FromHex("B5B5B580"));
	// Background | Default
	this->BackgroundOpaque = FLinearColor::FromSRGBColor(FColor::FromHex("F8F8F880"));
	// Foreground | Selection
	this->SelectedForeground = FLinearColor::FromSRGBColor(FColor::FromHex("FFFFFFFF"));
	this->UnselectedForeground = FLinearColor::FromSRGBColor(FColor::FromHex("000000FF"));
	this->SelectedForegroundOpaque = FLinearColor::FromSRGBColor(FColor::FromHex("000000FF"));
	this->UnselectedForegroundOpaque = FLinearColor::FromSRGBColor(FColor::FromHex("000000FF"));


	// CharacterHud | Interaction | Entry
	this->CharacterHudInteractionEntrySelectedBackground = FLinearColor::FromSRGBColor(FColor::FromHex("595959FF"));
	this->CharacterHudInteractionEntrySelectedForeground = FLinearColor::FromSRGBColor(FColor::FromHex("FFFFFFFF"));
	this->CharacterHudInteractionEntryUnselectedBackground = FLinearColor::FromSRGBColor(FColor::FromHex("B5B5B580"));
	this->CharacterHudInteractionEntryUnselectedForeground = FLinearColor::FromSRGBColor(FColor::FromHex("000000FF"));
}
