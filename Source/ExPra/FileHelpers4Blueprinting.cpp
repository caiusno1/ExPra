// Fill out your copyright notice in the Description page of Project Settings.

#include "ExPra.h"
#include "FileHelpers4Blueprinting.h"
bool UFileHelpers4Blueprinting::FileSaveString(FString SaveTextB, FString FileNameB)
{
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
}

bool UFileHelpers4Blueprinting::FileLoadString(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}




