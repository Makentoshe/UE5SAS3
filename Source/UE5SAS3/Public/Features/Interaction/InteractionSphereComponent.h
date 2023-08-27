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
 * This is an InteractionComponent with the Sphere collision. Those collision is used in interaction.
 * 
 * Component is responsible for triggering interaction availability via subsystem and checking is overlapped actor can be interacted.
 */
UCLASS(Blueprintable, BlueprintType)
class UE5SAS3_API UInteractionSphereComponent : public UUE5SASSphereComponent, public IInteractionComponent
{
	GENERATED_BODY()

	// Default constructor
	UInteractionSphereComponent();

	// Called when a component is registered, after Scene is set, but before CreateRenderState_Concurrent or OnCreatePhysicsState are called.
	virtual void OnRegister() override;

	// Called when a component is unregistered. Called after DestroyRenderState_Concurrent and OnDestroyPhysicsState are called.
	virtual void OnUnregister() override;

	// Default virtual destructor
	virtual ~UInteractionSphereComponent();


	/** Is component selected by some InteractorComponent */
	UPROPERTY(BlueprintReadOnly, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	bool IsSelected;

	/** Is component available for some InteractorComponent */
	UPROPERTY(BlueprintReadOnly, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	bool IsAvailable;

	/** Is component enabled. If true collision events will be triggered */
	UPROPERTY(EditAnywhere, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	bool IsInteractionEnabled;

	/** On each interaction broadcast event to InteractionSubsystem will be called */
	UPROPERTY(EditAnywhere, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	bool IsBroadcastEnabled;

	/** If broadcast enabled, those string will be broadcasted  */
	UPROPERTY(EditAnywhere, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	FString BroadcastStringId;


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


	// Called when something overlaps SphereComponent
	UFUNCTION()
	void OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Called when something overlaps SphereComponent
	UFUNCTION()
	void OnSphereComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:

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
	void OnInteractionComponentInteracted(const TScriptInterface<IInteractorComponent>& InteractorComponent);
	virtual void OnInteractionComponentInteracted_Implementation(const TScriptInterface<IInteractorComponent>& InteractorComponent) override;

};
