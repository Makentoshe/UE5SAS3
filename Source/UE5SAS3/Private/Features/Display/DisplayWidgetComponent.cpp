// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Display/DisplayWidgetComponent.h"

UDisplayWidgetComponent::UDisplayWidgetComponent() 
{
	// Default value
	mIsDisplayable = true;
}

void UDisplayWidgetComponent::HideDisplayWidget()
{
	// Making this component invisible also hides widget
	SetVisibility(false);
}