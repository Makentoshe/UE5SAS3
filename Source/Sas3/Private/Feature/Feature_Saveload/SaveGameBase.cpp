// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Saveload/SaveGameBase.h"

void USaveGameBase::ClearSerializedActors()
{
	this->SerializedActors.Empty();
}

void USaveGameBase::AddSerializedActor(FSaveloadActorStructure Structure)
{
	this->SerializedActors.Add(Structure);
}

TArray<FSaveloadActorStructure> USaveGameBase::GetSerializedActors()
{
	return this->SerializedActors;
}
