// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_CharacterHud/Structures/Wrappers/ObtainedItemWrapper.h"

UObtainedItemWrapper::UObtainedItemWrapper()
{
	this->ObtainedItemStructure = FObtainedItemStructure();
}

UObtainedItemWrapper::UObtainedItemWrapper(FObtainedItemStructure& Structure)
{
	this->ObtainedItemStructure = Structure;
}

UObtainedItemWrapper::~UObtainedItemWrapper()
{
}

FObtainedItemStructure UObtainedItemWrapper::GetObtainedItemStructure()
{
	return ObtainedItemStructure;
}
