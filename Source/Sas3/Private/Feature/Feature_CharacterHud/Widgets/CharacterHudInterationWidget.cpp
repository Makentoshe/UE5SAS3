// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_CharacterHud/Widgets/CharacterHudInterationWidget.h"

void UCharacterHudInterationWidget::AddInteractionEntry(UInteractionWrapper* InteractionWrapper)
{
	this->InteractionsContainer.Get()->AddItem(InteractionWrapper);
	this->OnInteractionAdded.Broadcast(InteractionWrapper);
}

void UCharacterHudInterationWidget::RemoveInteractionEntry(UInteractionWrapper* InteractionWrapper)
{   // Get current selected item index
	auto SelectedItem = this->InteractionsContainer.Get()->GetSelectedItem();
	auto SelectedItemIndex = this->InteractionsContainer.Get()->GetIndexForItem(SelectedItem);
	// Remove item 
	this->InteractionsContainer.Get()->RemoveItem(InteractionWrapper);
	this->OnInteractionRemoved.Broadcast(InteractionWrapper);
	// Change selection
	ChangeInteractionEntrySelection(FMath::Min(SelectedItemIndex, this->InteractionsContainer.Get()->GetNumItems() - 1));
}

void UCharacterHudInterationWidget::ChangeInteractionEntrySelection(int32 NewIndex)
{   // Change selection for the entry
	this->InteractionsContainer.Get()->ClearSelection();
	this->InteractionsContainer.Get()->SetSelectedIndex(NewIndex);
	// Scroll to the selected entry if it is off the screen
	auto Item = this->InteractionsContainer.Get()->GetItemAt(NewIndex);
	auto IsItemVisible = this->InteractionsContainer.Get()->IsItemVisible(Item);
	if (!IsItemVisible) {
		this->InteractionsContainer.Get()->ScrollIndexIntoView(NewIndex);
	}
	// Invoke interaction changed event
	this->OnInteractionChanged.Broadcast(NewIndex);
}

int32 UCharacterHudInterationWidget::GetCurrentInteractionsCount()
{
	return this->InteractionsContainer.Get()->GetNumItems();
}
