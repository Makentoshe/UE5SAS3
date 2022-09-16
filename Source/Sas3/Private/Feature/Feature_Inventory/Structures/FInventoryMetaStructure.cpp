// Fill out your copyright notice in the Description page of Project Settings.

#include <Sas3/Public/Feature/Feature_Inventory/Structures/FInventoryMetaStructure.h>

FInventoryMetaStructure::FInventoryMetaStructure()
{
	this->ItemCount = 0;
	this->StackSize = 10;
}

FInventoryMetaStructure::FInventoryMetaStructure(int32 ItemCount, int32 StackSize)
{
	this->ItemCount = ItemCount;
	this->StackSize = StackSize;
}

FInventoryMetaStructure::~FInventoryMetaStructure()
{
}

FInventoryMetaStructure& FInventoryMetaStructure::operator=(const FInventoryMetaStructure Structure)
{   // destroy current data
	this->~FInventoryMetaStructure();
	// refill fields
	this->ItemCount = Structure.ItemCount;
	this->StackSize = Structure.StackSize;
	// return reference
	return *this;
}
