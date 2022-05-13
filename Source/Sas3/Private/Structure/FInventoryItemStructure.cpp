// Fill out your copyright notice in the Description page of Project Settings.


#include "Structure/FInventoryItemStructure.h"

FInventoryItemStructure::FInventoryItemStructure(): FGameItemStructure()
{   // Main item info
	//this->Item = FGameItemStructure();
	this->Count = 0;
	// Metainfo
	this->StackSize = 10;
}

FInventoryItemStructure::FInventoryItemStructure(const FInventoryItemStructure& Structure, int32 Count): FGameItemStructure()
{   // Main item info
	this->Title = Structure.Title;
	this->Count = Count;
	// Metainfo
	this->StackSize = Structure.StackSize;
}
