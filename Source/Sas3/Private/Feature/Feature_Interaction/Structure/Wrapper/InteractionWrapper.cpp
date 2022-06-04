// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Interaction/Structure/Wrapper/InteractionWrapper.h"

UInteractionWrapper::UInteractionWrapper()
{
	this->InteractionStructure = FInteractionStructure();
}

UInteractionWrapper::UInteractionWrapper(FInteractionStructure& Structure, AActor* Actor)
{
	this->InteractionStructure = Structure;
	this->InteractableActor = Actor;
}

UInteractionWrapper::~UInteractionWrapper()
{
}

FInteractionStructure UInteractionWrapper::GetInteractionStructure()
{
	return InteractionStructure;
}

AActor* UInteractionWrapper::GetInteractableActor()
{
	return InteractableActor;
}

bool UInteractionWrapper::operator==(UInteractionWrapper* Wrapper)
{
	return this->InteractableActor == Wrapper->InteractableActor && this->InteractionStructure == Wrapper->InteractionStructure;
}
