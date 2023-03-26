// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Display/LabelDisplayWidgetComponent.h"

#include "Features/Display/LabelDisplayUserWidget.h"


void ULabelDisplayWidgetComponent::ShowDisplayWidget(const FSDisplayLabel Structure)
{
	// Get attached component widget
	auto LabelWidget = Cast<ULabelDisplayUserWidget>(GetWidget());

	// Set label string
	LabelWidget->SetLabelString(Structure.Label);

	// Show component
	SetVisibility(true);
}
