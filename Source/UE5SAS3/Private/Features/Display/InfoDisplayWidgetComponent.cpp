// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Display/InfoDisplayWidgetComponent.h"
#include "Features/Display/InfoDisplayUserWidget.h"


void UInfoDisplayWidgetComponent::ShowDisplayWidget(const FSDisplayInfo Structure)
{
	// Get attached component widget
	auto LabelWidget = Cast<UInfoDisplayUserWidget>(GetWidget());

	// Set label string
	LabelWidget->SetLabelString(Structure.Label);
	LabelWidget->SetDescriptionString(Structure.Description);

	// Show component
	SetVisibility(true);
}