// Fill out your copyright notice in the Description page of Project Settings.


#include <Sas3/Public/Items/Items/Structures/FGameItemStructure.h>

FGameItemStructure::FGameItemStructure()
{
	this->Title = FName(TEXT(""));
}

FGameItemStructure::~FGameItemStructure() {

}

// Allows to assign an object using = operator.
// 
// Note: this assign makes an copy of the object which allows us to avoid memory loss on base object change
FGameItemStructure& FGameItemStructure::operator=(const FGameItemStructure Structure)
{
	this->~FGameItemStructure();
	this->Title = Structure.Title;
	return *this;
}
