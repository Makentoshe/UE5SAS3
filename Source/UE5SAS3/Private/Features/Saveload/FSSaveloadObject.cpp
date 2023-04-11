// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Saveload/FSSaveloadObject.h"

FSSaveloadObject::FSSaveloadObject()
{
	IsActorDestroyed = true;
}

FSSaveloadObject::~FSSaveloadObject()
{
}

// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
FSSaveloadObject& FSSaveloadObject::operator=(const FSSaveloadObject Structure)
{
	this->~FSSaveloadObject();

	this->IsActorDestroyed = Structure.IsActorDestroyed;
	this->ActorTransform = Structure.ActorTransform;

	return *this;
}
