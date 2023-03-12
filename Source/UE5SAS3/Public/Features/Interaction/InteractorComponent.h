// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractorComponent.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractorComponent : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE5SAS3_API IInteractorComponent
{
	GENERATED_BODY()

	// This is the class that will be inherited to implement this interface.
public:

	/** Add a new InteractionComponent to the list of available interactions that Character can see */
	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
	void AddInteractionComponent(const TScriptInterface<IInteractionComponent> &Component);

	/** Remove InteractionComponent from the list of available interactions that Character can see */
	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
	void RemoveInteractionComponent(const TScriptInterface<IInteractionComponent> &Component);

	/** Return the list of available interactions that Character can see. Consumes empty array reference and rewrites it. Makes this way for bp compatibility */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void GetInteractionComponents(TArray<TScriptInterface<IInteractionComponent>>& Components);

	/** Event calls when InteractionComponent was interacted right before its own interaction event occurs */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteractionComponentInteracted(const TScriptInterface<IInteractionComponent>& Component);
};
