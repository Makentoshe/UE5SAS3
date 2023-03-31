// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Display/FSDisplayInfo.h"

FSDisplayInfo::FSDisplayInfo()
{
	this->Label = FString(TEXT(""));
	this->Description = FString(TEXT(""));
}

FSDisplayInfo::~FSDisplayInfo()
{
}

// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
FSDisplayInfo& FSDisplayInfo::operator=(const FSDisplayInfo Structure)
{
	this->~FSDisplayInfo();
	this->Label = Structure.Label;
	this->Description = Structure.Description;
	return *this;
}