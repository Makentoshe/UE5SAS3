// Fill out your copyright notice in the Description page of Project Settings.


#include <Sas3/Public/Feature/Feature_Interaction/Structure/FNearbyInteractionStructure.h>

FNearbyInteractionStructure::FNearbyInteractionStructure()
{
	this->Title = FName(TEXT(""));
	this->Description = FName(TEXT(""));
	this->NearbyInteractionType = NearbyInteractionType::None;
	this->Actor = nullptr;
}

FNearbyInteractionStructure::~FNearbyInteractionStructure()
{
}

FNearbyInteractionStructure& FNearbyInteractionStructure::operator=(const FNearbyInteractionStructure Structure)
{
	this->~FNearbyInteractionStructure();

	this->Title = Structure.Title;
	this->Description = Structure.Description;
	this->NearbyInteractionType = Structure.NearbyInteractionType;
	this->Actor = Structure.Actor;

	return *this;
}
