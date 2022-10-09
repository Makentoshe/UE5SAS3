// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Saveload/Structure/FSaveloadMetaStructure.h"

FSaveloadMetaStructure::FSaveloadMetaStructure()
{
	this->GeneralSlotTitle = "";
	this->TemporalSlotTitle = "";
}

FSaveloadMetaStructure::FSaveloadMetaStructure(FString BaseTitle)
{
	this->GeneralSlotTitle = FString(TEXT("General")).Append(BaseTitle);
	this->TemporalSlotTitle = FString(TEXT("Temporal")).Append(BaseTitle);
}

FSaveloadMetaStructure::~FSaveloadMetaStructure()
{
}
