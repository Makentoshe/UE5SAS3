// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Environment/EnvironmentItemActor.h"
#include "Kismet/KismetSystemLibrary.h"

void AEnvironmentItemActor::BeginPlay()
{
	// Initialize OnNearbyInteractionBeginEvent delegate
	FName FNameNearbyInteractionBegin("OnNearbyInteractionBeginEvent");
	FScriptDelegate FScriptDelegateNearbyInteractionBegin;
	FScriptDelegateNearbyInteractionBegin.BindUFunction(this, FNameNearbyInteractionBegin);
	this->OnNearbyInteractionBegin.Add(FScriptDelegateNearbyInteractionBegin);

	// Initialize OnNearbyInteractionEndEvent delegate
	FName FNameNearbyInteractionEnd("OnNearbyInteractionEndEvent");
	FScriptDelegate FScriptDelegateNearbyInteractionEnd;
	FScriptDelegateNearbyInteractionEnd.BindUFunction(this, FNameNearbyInteractionEnd);
	this->OnNearbyInteractionEnd.Add(FScriptDelegateNearbyInteractionEnd);
}

void AEnvironmentItemActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	this->OnNearbyInteractionEnd.Clear();
	this->OnNearbyInteractionBegin.Clear();
}

void AEnvironmentItemActor::OnNearbyInteractionBeginEvent(AActor* OverlappedActor)
{
	auto string1 = UKismetSystemLibrary::GetDisplayName(this).Append("-").Append(GameItem.Title.ToString());
	auto string2 = UKismetSystemLibrary::GetDisplayName(OverlappedActor);

	FString s = FString(TEXT("Event for ")).Append(string1).Append(" begin overlap ").Append(string2);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, s);
}

void AEnvironmentItemActor::OnNearbyInteractionEndEvent(AActor* OverlappedActor)
{
	auto string1 = UKismetSystemLibrary::GetDisplayName(this).Append("-").Append(GameItem.Title.ToString());
	auto string2 = UKismetSystemLibrary::GetDisplayName(OverlappedActor);

	FString s = FString(TEXT("Event for ")).Append(string1).Append(" end overlap ").Append(string2);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, s);
}
