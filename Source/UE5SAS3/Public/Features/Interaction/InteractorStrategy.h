// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CollisionQueryParams.h"
#include "InteractorStrategy.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract, Blueprintable)
class UE5SAS3_API UInteractorStrategy : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void GetInteractorComponent(const TArray<TScriptInterface<IInteractionComponent>>& Components, TScriptInterface<IInteractionComponent>& Component);
		//virtual void GetInteractorComponent_Implemented(const TArray<TScriptInterface<IInteractionComponent>>& Components, TScriptInterface<IInteractionComponent>& Component);

protected:
	// Custom LineTraceByChannel
	UFUNCTION(BlueprintCallable, meta = (BlueprintProtected))
		bool LineTraceByChannel(struct FHitResult& OutHit,const FVector& Start,const FVector& End, ECollisionChannel TraceChannel);
};
