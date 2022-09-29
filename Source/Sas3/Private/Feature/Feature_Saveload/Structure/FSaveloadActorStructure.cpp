// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Saveload/Structure/FSaveloadActorStructure.h"

FSaveloadActorStructure::FSaveloadActorStructure()
{
	FSaveloadActorStructure(FName(TEXT("")), FTransform(), TArray<uint8>(), nullptr);
}

FSaveloadActorStructure::FSaveloadActorStructure(FName ActorIdentifier, FTransform Transform, TArray<uint8> ByteData, UInventorableComponentSaveloadWrapper* InventorableComponentWrapper)
{
	this->ActorIdentifier = ActorIdentifier;
	this->Transform = Transform;
	this->ByteData = ByteData;
	this->InventorableComponentWrapper = InventorableComponentWrapper;
}

FSaveloadActorStructure::~FSaveloadActorStructure()
{
	if(this->InventorableComponentWrapper) delete this->InventorableComponentWrapper;
}
