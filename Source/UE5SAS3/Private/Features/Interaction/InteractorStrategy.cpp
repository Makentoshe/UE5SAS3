// Fill out your copyright notice in the Description page of Project Settings.

#include "Features/Interaction/InteractorStrategy.h"

#include "CollisionQueryParams.h"

bool UInteractorStrategy::LineTraceByChannel(struct FHitResult& OutHit,const FVector& Start,const FVector& End,ECollisionChannel TraceChannel) {
	UWorld* World = GetWorld();

	FCollisionQueryParams CollisionParams = FCollisionQueryParams::DefaultQueryParam;

	FCollisionResponseParams ResponseParam = FCollisionResponseParams::DefaultResponseParam;
	ResponseParam.CollisionResponse.Visibility = true;

	return World->LineTraceSingleByChannel(OutHit, Start, End, TraceChannel, CollisionParams, ResponseParam);
}
