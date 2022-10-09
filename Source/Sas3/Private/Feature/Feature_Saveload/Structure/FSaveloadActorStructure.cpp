// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Saveload/Structure/FSaveloadActorStructure.h"

FSaveloadActorStructure::FSaveloadActorStructure()
{
	this->ActorIdentifier = FName(TEXT(""));
	this->Transform = FTransform();
}

FSaveloadActorStructure::FSaveloadActorStructure(FName ActorIdentifier, FTransform Transform)
{
	this->ActorIdentifier = ActorIdentifier;
	this->Transform = Transform;
}

FSaveloadActorStructure::~FSaveloadActorStructure()
{
	
}
