// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Battle/Structures/FBattleStateStructure.h"

FBattleStateStructure::FBattleStateStructure()
{
	this->State = EBattleState::Uninitialized;
}

FBattleStateStructure::FBattleStateStructure(EBattleState State)
{
	this->State = State;
}

FBattleStateStructure::~FBattleStateStructure()
{
}
