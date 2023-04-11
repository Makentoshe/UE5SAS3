// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Features/Saveload/FSSaveloadObject.h"
#include "Features/Saveload/SaveloadComponent.h"

#include "SaveloadActorComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSaveloadActorComponentSerialize, const FSSaveloadObject&, SaveloadObject);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSaveloadActorComponentDeserialize, const FSSaveloadObject&, SaveloadObject);

/**
* 
*/
UCLASS(Blueprintable, BlueprintType, Category = "Saveload Feature")
class UE5SAS3_API USaveloadActorComponent : public UActorComponent, public ISaveloadComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USaveloadActorComponent();


	/** Delegate for invoking each time owner serializes */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = "Saveload Feature", meta = (AllowPrivateAccess = "true"))
	FOnSaveloadActorComponentSerialize OnSerializeDelegate;

	/** Delegate for invoking each time owner deserializes */
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, BlueprintReadWrite, Category = "Saveload Feature", meta = (AllowPrivateAccess = "true"))
	FOnSaveloadActorComponentDeserialize OnDeserializeDelegate;


public:	
	// From SaveloadComponent interface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Saveload Feature")
	void Serialize(FSSaveloadObject& SaveloadObject);
	virtual void Serialize_Implementation(FSSaveloadObject& SaveloadObject);

	// From SaveloadComponent interface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Saveload Feature")
	void Deserialize(const FSSaveloadObject& SaveloadObject);	
	virtual void Deserialize_Implementation(const FSSaveloadObject& SaveloadObject);

	// From SaveloadComponent interface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Saveload Feature")
	AActor* GetOwnerActor();
	virtual AActor* GetOwnerActor_Implementation();
};
