// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_Battle/Subsystems/BattleGameInstanceSubsystem.h"


UBattleGameInstanceSubsystem::UBattleGameInstanceSubsystem() 
{

}

void UBattleGameInstanceSubsystem::InitializeBattle()
{
	this->BattleState.State = EBattleState::Initialized;
	this->OnBattleStateChanged.Broadcast(this->BattleState);
}

void UBattleGameInstanceSubsystem::BeginBattle()
{
	this->BattleState.State = EBattleState::Started;
	this->OnBattleStateChanged.Broadcast(this->BattleState);
}

void UBattleGameInstanceSubsystem::FinishBattle()
{
	this->BattleState.State = EBattleState::Finished;
	this->OnBattleStateChanged.Broadcast(this->BattleState);
}

void UBattleGameInstanceSubsystem::UninitializeBattle()
{
	this->BattleState.State = EBattleState::Uninitialized;
	this->OnBattleStateChanged.Broadcast(this->BattleState);
}
