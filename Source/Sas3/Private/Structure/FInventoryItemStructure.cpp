// Fill out your copyright notice in the Description page of Project Settings.


#include "Structure/FInventoryItemStructure.h"

FInventoryItemStructure::FInventoryItemStructure()
{   // Main item info
	this->Item = FGameItemStructure();
	this->Count = 0;
	// Metainfo
	this->StackSize = 10;
}

FInventoryItemStructure::FInventoryItemStructure(const FInventoryItemStructure& Structure, int32 Count)
{   // Main item info
	this->Item = Structure.Item;
	this->Count = Count;
	// Metainfo
	this->StackSize = Structure.StackSize;
}

FInventoryItemStructure::~FInventoryItemStructure()
{
}
