// Fill out your copyright notice in the Description page of Project Settings.


#include "Structure/FNearbyActionStructure.h"

FNearbyActionStructure::FNearbyActionStructure()
{
	this->ActionTitle = FName(TEXT(""));
	this->ActionDescription = FName(TEXT(""));
	this->ActionType = ENearbyActionType::None;
}
