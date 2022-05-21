// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryUiActorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowInventoryWidget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHideInventoryWidget);

UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UInventoryUiActorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when a component is registered, after Scene is set, but before CreateRenderState_Concurrent or OnCreatePhysicsState are called.
	virtual void OnRegister() override;

	// Called when a component is unregistered. Called after DestroyRenderState_Concurrent and OnDestroyPhysicsState are called.
	virtual void OnUnregister() override;

public:	
	// Sets default values for this component's properties
	UInventoryUiActorComponent();
	
	// Calls when inventory widget should be displayed
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Inventory Delegates")
	FOnShowInventoryWidget OnShowInventoryWidget;

	// Calls when inventory widget should be hide
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Inventory Delegates")
	FOnHideInventoryWidget OnHideInventoryWidget;
};
