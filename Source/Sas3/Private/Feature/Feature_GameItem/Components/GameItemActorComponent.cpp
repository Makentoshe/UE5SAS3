// Fill out your copyright notice in the Description page of Project Settings.


#include "Feature/Feature_GameItem/Components/GameItemActorComponent.h"

// Default constructor
UGameItemActorComponent::UGameItemActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame. 
	PrimaryComponentTick.bCanEverTick = false;
}

UGameItemActorComponent::~UGameItemActorComponent()
{
}
