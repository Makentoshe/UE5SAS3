// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Interaction/Structure/FInteractionStructure.h"

FInteractionStructure::FInteractionStructure()
{
	this->Title = FName(TEXT(""));
	this->Description = FName(TEXT(""));
	this->NearbyInteractionType = NearbyInteractionType::None;
}

FInteractionStructure::~FInteractionStructure()
{
}

FInteractionStructure& FInteractionStructure::operator=(const FInteractionStructure Structure)
{
	this->~FInteractionStructure();

	this->Title = Structure.Title;
	this->Description = Structure.Description;
	this->NearbyInteractionType = Structure.NearbyInteractionType;

	return *this;
}

bool FInteractionStructure::operator==(const FInteractionStructure& Structure)
{
	return this->Title == Structure.Title && this->Description == Structure.Description && this->NearbyInteractionType == Structure.NearbyInteractionType;
}

bool FInteractionStructure::operator!=(const FInteractionStructure& Structure)
{
	return this->Title != Structure.Title || this->Description != Structure.Description || this->NearbyInteractionType != Structure.NearbyInteractionType;
}
