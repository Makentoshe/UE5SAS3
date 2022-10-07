// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Interaction/Structure/Wrapper/InteractionWrapper.h"

UInteractionWrapper::UInteractionWrapper()
{
	this->InteractionStructure = FInteractionStructure();
}

UInteractionWrapper::UInteractionWrapper(FInteractionStructure& Structure, UInteractableSphereComponent* Component)
{
	this->InteractionStructure = Structure;
	this->InteractableComponent = Component;
}

UInteractionWrapper::~UInteractionWrapper()
{
}

bool UInteractionWrapper::operator==(UInteractionWrapper* Wrapper)
{
	return this->InteractableComponent == Wrapper->InteractableComponent && this->InteractionStructure == Wrapper->InteractionStructure;
}
