// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Interaction/Structure/Wrapper/NearbyInteractionWrapper.h"

// Sets default values
UNearbyInteractionWrapper::UNearbyInteractionWrapper()
{   
	this->NearbyInteractionStructure = FNearbyInteractionStructure();
}

UNearbyInteractionWrapper::UNearbyInteractionWrapper(FNearbyInteractionStructure& Structure)
{   // copy Structure
	this->NearbyInteractionStructure = Structure;
}

UNearbyInteractionWrapper::~UNearbyInteractionWrapper()
{
}

FNearbyInteractionStructure UNearbyInteractionWrapper::GetNearbyInteractionStructure()
{
	return this->NearbyInteractionStructure;
}
