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
	bool first = true;
	for (auto& soa : testsoa)
	{
		if (first)
		{
			first = false;
			JoinedStr += TEXT("Soa ");
		}
		else
		{
			JoinedStr += TEXT(" ");
		}
		JoinedStr += FString::SanitizeFloat(soa);
	}
	first = true;
	JoinedStr += TEXT("\n");
	for (auto& res : correct)
	{
		if (first)
		{
			first = false;
			JoinedStr += TEXT("CorrectBoxChoosen ");
		}
		else
		{
			JoinedStr += TEXT(" ");
		}
		JoinedStr += FString::Printf(TEXT("%d"), res);
	}
	first = true;
	JoinedStr += TEXT("\n");
	for (auto& colch : timeUntilColorChanged)
	{
		if (first)
		{
			first = false;
			JoinedStr += TEXT("TimeBoxcolorIsVisible ");
		}
		else
		{
			JoinedStr += TEXT(" ");
		}
		JoinedStr += FString::SanitizeFloat(colch);
	}
	return FFileHelper::SaveStringToFile(JoinedStr, *(FPaths::GameDir() + identifier+"_testdata.csv"));
}

bool UFileHelpers4Blueprinting::FileLoadString(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}