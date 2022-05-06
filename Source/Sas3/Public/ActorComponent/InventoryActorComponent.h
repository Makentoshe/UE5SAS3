// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryActorComponent.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Disabled;

	// 
	FInventoryItem() 
	{
		this->Title = FName(TEXT(""));
		this->Disabled = FName(TEXT("Debug text"));
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SAS3_API UInventoryActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public: 
	// Defines how many stacks of items might be in the inventory
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory Settings")
	int32 InventorySize;

	// Defines how many items might be in one stack
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory Settings")
	int32 StackSize;
};
