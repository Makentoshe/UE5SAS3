// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Features/Feature/Component/UE5SASSphereComponent.h"
#include "Features/Interaction/InteractionComponent.h"

#include "InteractionSphereComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractionSphereComponentInteractionAvailable);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractionSphereComponentInteractionUnavailable);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractionSphereComponentInteractionSelected);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractionSphereComponentInteractionUnselected);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionSphereComponentInteract, const TScriptInterface<IInteractorComponent>&, InteractorComponent);
/**
 *  
 */
UCLASS(Blueprintable, BlueprintType)
class UE5SAS3_API UInteractionSphereComponent : public UUE5SASSphereComponent, public IInteractionComponent
{
	GENERATED_BODY()

	/** Is component selected. Only one component can be selected at the same time. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	bool IsSelected;

	/** Is component available. Several components can be at the same time */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	bool IsAvailable;

	/** Delegate for invoking each time on InteractionComponent becomes available */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	FOnInteractionSphereComponentInteractionAvailable OnInteractionComponentAvailableDelegate;

	/** Delegate for invoking each time on InteractionComponent becomes unavailable */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	FOnInteractionSphereComponentInteractionUnavailable OnInteractionComponentUnavailableDelegate;

	/** Delegate for invoking each time on InteractionComponent becomes selected */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	FOnInteractionSphereComponentInteractionSelected OnInteractionComponentSelectedDelegate;

	/** Delegate for invoking each time on InteractionComponent becomes unselected */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	FOnInteractionSphereComponentInteractionUnselected OnInteractionComponentUnselectedDelegate;

	/** Delegate for invoking each time on InteractorComponent invokes interaction */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	FOnInteractionSphereComponentInteract OnInteractionComponentInteractDelegate;

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FVector GetWorldLocationFromOwnerActor();
	virtual FVector GetWorldLocationFromOwnerActor_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentAvailable();
	virtual void OnInteractionComponentAvailable_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentUnavailable();
	virtual void OnInteractionComponentUnavailable_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentSelected();
	virtual void OnInteractionComponentSelected_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentUnselected();
	virtual void OnInteractionComponentUnselected_Implementation() override;

	/** Interaction with component owner should be performed */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void Interact(const TScriptInterface<IInteractorComponent>& InteractorComponent);
	virtual void Interact_Implementation(const TScriptInterface<IInteractorComponent>& InteractorComponent) override;

};
