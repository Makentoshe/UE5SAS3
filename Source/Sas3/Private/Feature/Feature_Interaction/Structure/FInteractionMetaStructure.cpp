// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Interaction/Structure/FInteractionMetaStructure.h"

FInteractionMetaStructure::FInteractionMetaStructure()
{
	this->Description = FName(TEXT(""));
}

FInteractionMetaStructure::~FInteractionMetaStructure()
{
}

FInteractionMetaStructure& FInteractionMetaStructure::operator=(const FInteractionMetaStructure Structure)
{
	this->~FInteractionMetaStructure();

	this->Description = Structure.Description;

	return *this;
}
