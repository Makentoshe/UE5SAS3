// Fill out your copyright notice in the Description page of Project Settings.


#include "Structure/FInventoryItemStructure.h"

FInventoryItemStructure::FInventoryItemStructure()
{
	this->Title = FName(TEXT(""));
	this->Count = 0;
	this->IsStacking = false;
}

FInventoryItemStructure::~FInventoryItemStructure()
{
}
