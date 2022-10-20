// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "FSaveloadMetaStructure.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct SAS3_API FSaveloadMetaStructure : public FTableRowBase
{
	GENERATED_BODY()

public:
	FSaveloadMetaStructure();
	FSaveloadMetaStructure(FString BaseTitle);

	~FSaveloadMetaStructure();

	UPROPERTY(BlueprintReadWrite)
	FString GeneralSlotTitle;

	UPROPERTY(BlueprintReadWrite)
	FString TemporalSlotTitle;
};
