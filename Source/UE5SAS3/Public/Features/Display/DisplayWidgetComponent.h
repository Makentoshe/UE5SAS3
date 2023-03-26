// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "DisplayWidgetComponent.generated.h"

/**
 * Base component for displaying 
 * 
 * Note: ShowDisplayWidget should be implemented in each child separately
 */
UCLASS(Abstract, BlueprintType, Blueprintable, Category = "Display Feature")
class UE5SAS3_API UDisplayWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

	/** Property for enabling/disabling displaying */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display Feature", meta = (AllowPrivateAccess = "true", DisplayName = "IsDisplayable"))
	bool mIsDisplayable;

public:
	/** Default constructor */
	UDisplayWidgetComponent();

	UFUNCTION(BlueprintCallable, Category = "Display Feature")
	void HideDisplayWidget();
	
public:

	FORCEINLINE bool IsDisplayable() const { return mIsDisplayable; }
	FORCEINLINE void SetDisplayable(bool value) { mIsDisplayable = value; }
};
