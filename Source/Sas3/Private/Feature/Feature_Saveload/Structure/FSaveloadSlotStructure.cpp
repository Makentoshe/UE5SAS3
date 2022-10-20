// Fill out your copyright notice in the Description page of Project Settings.


#include <Sas3/Public/Feature/Feature_Saveload/Structure/FSaveloadSlotStructure.h>


FSaveloadSlotStructure::FSaveloadSlotStructure()
{
	this->Filename = TEXT("");
	this->IsInitialized = false;
}

FSaveloadSlotStructure::FSaveloadSlotStructure(FString Filename)
{
	this->Filename = Filename;
	this->IsInitialized = true;
}

FSaveloadSlotStructure::~FSaveloadSlotStructure()
{
	this->IsInitialized = false;
}

