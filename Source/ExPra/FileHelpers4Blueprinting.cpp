// Fill out your copyright notice in the Description page of Project Settings.
#include "ExPra.h"
#include "FileHelpers4Blueprinting.h"
bool UFileHelpers4Blueprinting::FileSaveString(FString SaveTextB, FString FileNameB)
{
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
}

bool UFileHelpers4Blueprinting::FileSaveTestResult(const TArray<float>& testsoa, const TArray<float>& timeUntilColorChanged ,const TArray<bool>& correct, FString identifier)
{
	FString JoinedStr;
	for (auto& soa : testsoa)
	{
		JoinedStr += FString::SanitizeFloat(soa);
		JoinedStr += TEXT(" ");
	}
	JoinedStr += TEXT("\n");
	for (auto& res : correct)
	{
		JoinedStr += FString::Printf(TEXT("%d"), res);
		JoinedStr += TEXT(" ");
	}
	JoinedStr += TEXT("\n");
	for (auto& colch : timeUntilColorChanged)
	{
		JoinedStr += FString::SanitizeFloat(colch);
		JoinedStr += TEXT(" ");
	}
	return FFileHelper::SaveStringToFile(JoinedStr, *(FPaths::GameDir() + identifier+"_testdata.csv"));
}

bool UFileHelpers4Blueprinting::FileLoadString(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}