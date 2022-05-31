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

//Note: Wrappers contains only structures so we should compare them
bool UNearbyInteractionWrapper::operator==(UNearbyInteractionWrapper* Wrapper)
{
	return this->NearbyInteractionStructure == Wrapper->NearbyInteractionStructure;
}
