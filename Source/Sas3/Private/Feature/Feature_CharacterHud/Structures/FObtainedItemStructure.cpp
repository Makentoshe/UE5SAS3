// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_CharacterHud/Structures/FObtainedItemStructure.h"

FObtainedItemStructure::FObtainedItemStructure()
{
	this->Title = FName(TEXT(""));
	this->Count = 0;
	this->ShowCount = false;
}

FObtainedItemStructure::~FObtainedItemStructure()
{
}

FObtainedItemStructure& FObtainedItemStructure::operator=(const FObtainedItemStructure Structure)
{
	this->~FObtainedItemStructure();

	this->Title = Structure.Title;
	this->Count = Structure.Count;
	this->ShowCount= Structure.ShowCount;

	return *this;
}
