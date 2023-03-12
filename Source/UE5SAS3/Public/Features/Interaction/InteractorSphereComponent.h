// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Features/Feature/Component/UE5SASSphereComponent.h"
#include "Features/Interaction/InteractionComponent.h"
#include "Features/Interaction/InteractorComponent.h"

#include "InteractorSphereComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractorSphereComponentInteractionAvailable, const TScriptInterface<IInteractionComponent>&, InteractionComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractorSphereComponentInteractionUnavailable, const TScriptInterface<IInteractionComponent>&, InteractionComponent);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UE5SAS3_API UInteractorSphereComponent : public UUE5SASSphereComponent, public IInteractorComponent
{
	GENERATED_BODY()
	
	/** Component selected at the moment. Can be null */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	TScriptInterface<IInteractionComponent> SelectedInteractionComponent;

	/** Available components that can be selected. Can be empty */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	TArray<TScriptInterface<IInteractionComponent>> AvailableInteractionComponents;

	/** Delegate for invoking each time on InteractionComponent becomes available */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	FOnInteractorSphereComponentInteractionAvailable OnInteractionComponentAvailableDelegate;

	/** Delegate for invoking each time on InteractionComponent becomes unavailable */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	FOnInteractorSphereComponentInteractionUnavailable OnInteractionComponentUnavailableDelegate;

public:

	// From InteractorComponent interface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void AddInteractionComponent(const TScriptInterface<IInteractionComponent>& InteractionComponent);
	virtual void AddInteractionComponent_Implementation(const TScriptInterface<IInteractionComponent>& InteractionComponent);

	// From InteractorComponent interface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void RemoveInteractionComponent(const TScriptInterface<IInteractionComponent>& InteractionComponent);
	virtual void RemoveInteractionComponent_Implementation(const TScriptInterface<IInteractionComponent>& InteractionComponent);

	// From InteractorComponent interface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void GetInteractionComponents(TArray<TScriptInterface<IInteractionComponent>>& InteractionComponents);
	virtual void GetInteractionComponents_Implementation(TArray<TScriptInterface<IInteractionComponent>>& InteractionComponents);


public:
	/** Returns currently selected InteractionComponent **/
	FORCEINLINE class TScriptInterface<IInteractionComponent> GetSelectedInteractionComponent() const { return SelectedInteractionComponent; }

	/** Returns SelectedInteractionComponent **/
	FORCEINLINE class TArray<TScriptInterface<IInteractionComponent>> GetAvailableInteractionComponents() const { return AvailableInteractionComponents; }
};
