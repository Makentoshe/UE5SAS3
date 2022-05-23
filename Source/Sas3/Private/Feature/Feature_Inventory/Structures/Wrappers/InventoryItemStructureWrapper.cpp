// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Inventory/Structures/Wrappers/InventoryItemStructureWrapper.h"

UInventoryItemStructureWrapper::UInventoryItemStructureWrapper()
{
	this->InventoryItemStructure = FInventoryItemStructure();
}

UInventoryItemStructureWrapper::UInventoryItemStructureWrapper(FInventoryItemStructure Structure)
{
	this->InventoryItemStructure = Structure;
}
