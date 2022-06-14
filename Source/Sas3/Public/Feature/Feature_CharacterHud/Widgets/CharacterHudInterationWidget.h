// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListView.h"

#include "Feature/Features/Widgets/BaseWidget.h"
#include "Feature/Feature_Interaction/Structure/Wrapper/InteractionWrapper.h"

#include "CharacterHudInterationWidget.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractionAdded, UInteractionWrapper*, InteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractionRemoved, UInteractionWrapper*, InteractionWrapper);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractionChanged, int32, NewIndex);

/**
 * Widget that displays interactable items on the screen during gameplay
 */
UCLASS(BlueprintType, Abstract)
class SAS3_API UCharacterHudInterationWidget : public UBaseWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void AddInteractionEntry(UInteractionWrapper* InteractionWrapper);

	UFUNCTION(BlueprintCallable)
	void RemoveInteractionEntry(UInteractionWrapper* InteractionWrapper);

	UFUNCTION(BlueprintCallable)
	void ChangeInteractionEntrySelection(int32 NewIndex);

	UFUNCTION(BlueprintCallable, Category = "CharacterHud | Functions")
	int32 GetCurrentInteractionsCount();

public:
	// Event called when new interaction wrapper was added to the InteractionsContainer
	UPROPERTY(BlueprintAssignable, Category = "Interactor Delegates")
	FInteractionAdded OnInteractionAdded;

	// Event called when new interaction wrapper was removed from the InteractionsContainer
	UPROPERTY(BlueprintAssignable, Category = "Interactor Delegates")
	FInteractionRemoved OnInteractionRemoved;

	// Event called when new interaction wrapper was removed from the InteractionsContainer
	UPROPERTY(BlueprintAssignable, Category = "Interactor Delegates")
	FInteractionChanged OnInteractionChanged;

protected:
	// Widget to use to display interactable items
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<class UListView> InteractionsContainer;
};
