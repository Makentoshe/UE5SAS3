// Fill out your copyright notice in the Description page of Project Settings.


#include "Features/Display/FSDisplayLabel.h"

FSDisplayLabel::FSDisplayLabel()
{
	this->Label = FString(TEXT(""));
}

FSDisplayLabel::~FSDisplayLabel() {

}


// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
FSDisplayLabel& FSDisplayLabel::operator=(const FSDisplayLabel Structure)
{
	this->~FSDisplayLabel();
	this->Label = Structure.Label;
	return *this;
}