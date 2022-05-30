// Fill out your copyright notice in the Description page of Project Settings.

#include "Feature/Feature_Interaction/Components/InteractorActorComponent.h"
#include "Feature/Feature_Inventory/Interfaces/InventoryActorComponentHolder.h"
#include "Feature/Feature_Ui_Obtained/Interfaces/ObtainedActorComponentHolder.h"
#include "Feature/Feature_Interaction/Interfaces/InteractorUiActorComponentHolder.h"

// Sets default values for this component's properties
UInteractorActorComponent::UInteractorActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when a component is registered, after Scene is set, but before CreateRenderState_Concurrent or OnCreatePhysicsState are called.
void UInteractorActorComponent::OnRegister()
{
	Super::OnRegister();

	// Setup InventoryActorComponent variable
	if (GetOwner()->GetClass()->ImplementsInterface(UInventoryActorComponentHolder::StaticClass())) {
		this->InventoryActorComponent = IInventoryActorComponentHolder::Execute_GetInventoryActorComponent(GetOwner());
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Error: Owner doesn't contents InventoryActorComponent"));
	}

	// Setup ObtainedActorComponent variable
	if (GetOwner()->GetClass()->ImplementsInterface(UObtainedActorComponentHolder::StaticClass())) {
		this->ObtainedActorComponent = IObtainedActorComponentHolder::Execute_GetObtainedActorComponent(GetOwner());
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Error: Owner doesn't contents InteractorActorComponent"));
	}

	// Setup InteractorUiActorComponent variable
	if (GetOwner()->GetClass()->ImplementsInterface(UInteractorUiActorComponentHolder::StaticClass())) {
		this->InteractorUiActorComponent = IInteractorUiActorComponentHolder::Execute_GetInteractorUiActorComponent(GetOwner());
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Error: Owner doesn't contents InteractorActorComponent"));
	}
}

// Called when a component is unregistered.Called after DestroyRenderState_Concurrentand OnDestroyPhysicsState are called.
void UInteractorActorComponent::OnUnregister()
{
	Super::OnUnregister();

	this->InventoryActorComponent = nullptr;
	this->InteractorUiActorComponent = nullptr;
}
