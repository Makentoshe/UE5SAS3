// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Feature/Feature_Interaction/Structure/Wrapper/InteractionWrapper.h"
#include "Feature/Feature_CharacterHud/Widgets/CharacterHudObtainerWidget.h"
#include "Feature/Feature_CharacterHud/Widgets/CharacterHudInterationWidget.h"

#include "CharacterHudActorComponent.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterHudComponentInvalidOwnerPawn, AActor*, PretendsToBePawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterHudComponentInvalidPlayerController, AController*, PretendsToBePlayerController);


UCLASS(BlueprintType, Abstract, Blueprintable, Meta = (BlueprintSpawnableComponent))
class SAS3_API UCharacterHudActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Default constructor
	UCharacterHudActorComponent();

protected:
	// Called when a component is registered, after Scene is set, but before CreateRenderState_Concurrent or OnCreatePhysicsState are called.
	virtual void OnRegister() override;

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called when a component is unregistered. Called after DestroyRenderState_Concurrent and OnDestroyPhysicsState are called.
	virtual void OnUnregister() override;


public:
	// Called when interaction should be added to the hud
	UFUNCTION(BlueprintCallable, Category = "CharacterHud | Functions | Interactions")
	void AddInteraction(UInteractionWrapper* InteractionWrapper);

	// Called when interaction should be removed from the hud
	UFUNCTION(BlueprintCallable, Category = "CharacterHud | Functions | Interactions")
	void RemoveInteraction(UInteractionWrapper* InteractionWrapper);

	// Called when interaction selection should be changed in the hud
	UFUNCTION(BlueprintCallable, Category = "CharacterHud | Functions | Interactions")
	void ChangeInteractionSelection(int32 NewIndex);


protected:
	// Reference to the owners controller
	UPROPERTY(BlueprintReadWrite, Category = "CharacterHud | Owner")
	TObjectPtr<APlayerController> OwnerController;

	// Reference to the owner
	UPROPERTY(BlueprintReadWrite, Category = "CharacterHud | Owner")
	TObjectPtr<APawn> OwnerPawn;

	UPROPERTY(BlueprintReadWrite, Category = "CharacterHud | Properties | Widgets")
	TObjectPtr<UCharacterHudObtainerWidget> ObtainingsWidget;

	UPROPERTY(BlueprintReadWrite, Category = "CharacterHud | Properties | Widgets")
	TObjectPtr<UCharacterHudInterationWidget> InteractionsWidget;



protected:
	// Calls when getting a valid owner pawn fails
	UPROPERTY(BlueprintAssignable, Category = "CharacterHud | Delegates | Errors")
	FCharacterHudComponentInvalidOwnerPawn OnInvalidOwnerPawn;

	// Calls when getting a valid owner pawn fails
	UPROPERTY(BlueprintAssignable, Category = "CharacterHud | Delegates | Errors")
	FCharacterHudComponentInvalidPlayerController OnInvalidPlayerController;
};
