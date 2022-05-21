// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Sas3/Public/Feature/Feature_Inventory/Components/InventoryActorComponent.h>
#include "InteractorUiActorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddNearbyInteractionUi, ANearbyInteractionWrapper*, Wrapper);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveNearbyInteractionUi, ANearbyInteractionWrapper*, Wrapper);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeSelectedNearbyInteractionIndexUi, int32, NewIndex);

UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UInteractorUiActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractorUiActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
public:
	// Calls when new interaction should be added to the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnAddNearbyInteractionUi OnAddNearbyInteraction;

	// Calls when new interaction should be removed from the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnRemoveNearbyInteractionUi OnRemoveNearbyInteraction;

	// Calls when selection was changed in the interactions list
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Interactor Delegates")
	FOnChangeSelectedNearbyInteractionIndexUi OnChangeSelectedNearbyInteractionIndex;
};
