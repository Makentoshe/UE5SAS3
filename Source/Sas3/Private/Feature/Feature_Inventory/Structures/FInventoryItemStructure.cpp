// Fill out your copyright notice in the Description page of Project Settings.


#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryItemStructure.h>

FInventoryItemStructure::FInventoryItemStructure(): FGameItemStructure()
{   // Main item info
	//this->Item = FGameItemStructure();
	this->Count = 0;
	// Metainfo
	this->StackSize = 10;
}

FInventoryItemStructure::~FInventoryItemStructure()
{
}

FInventoryItemStructure::FInventoryItemStructure(const FInventoryItemStructure& Structure, int32 Count): FGameItemStructure()
{   // Main item info
	this->Title = Structure.Title;
	this->Count = Count;
	// Metainfo
	this->StackSize = Structure.StackSize;
}

FInventoryItemStructure& FInventoryItemStructure::operator=(const FInventoryItemStructure Structure)
{   
	this->~FInventoryItemStructure();
	
	this->Title = Structure.Title;
	this->Count = Structure.Count;
	this->StackSize = Structure.StackSize;

	return *this;
}
