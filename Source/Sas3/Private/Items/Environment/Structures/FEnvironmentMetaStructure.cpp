// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Environment/Structures/FEnvironmentMetaStructure.h"

FEnvironmentMetaStructure::FEnvironmentMetaStructure()
{
	this->Description = FName(TEXT(""));
}

FEnvironmentMetaStructure::~FEnvironmentMetaStructure()
{
}

FEnvironmentMetaStructure& FEnvironmentMetaStructure::operator=(const FEnvironmentMetaStructure Structure)
{   // destory current data
	this->~FEnvironmentMetaStructure();
	// fillup with new data
	this->Description = Structure.Description;
	// return reference
	return *this;
}

