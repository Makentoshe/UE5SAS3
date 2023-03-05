// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include <UE5SAS3/Public/Features/Interaction/InteractionComponent.h>

#include "InteractorActorComponent.generated.h"


UCLASS(BlueprintType, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5SAS3_API UInteractorActorComponent : public UActorComponent
{
	GENERATED_BODY()

	/** Component selected at the moment */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	TScriptInterface<IInteractionComponent> SelectedInteractionComponent;

public:	
	// Sets default values for this component's properties
	UInteractorActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	/** Returns SelectedInteractionComponent **/
	FORCEINLINE class TScriptInterface<IInteractionComponent> GetSelectedInteractionComponent() const { return SelectedInteractionComponent; }
};
