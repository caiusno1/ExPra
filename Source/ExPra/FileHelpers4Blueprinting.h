// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileHelpers4Blueprinting.generated.h"

/**
 * 
 */
UCLASS()
class EXPRA_API UFileHelpers4Blueprinting : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "save")
		static bool FileSaveString(FString SaveTextB, FString FileNameB);

	UFUNCTION(BlueprintCallable, Category = "save")
		static bool  FileSaveTestResult(const TArray<float>& testsoa, const TArray<float>& timeUntilColorChanged, const TArray<bool>& correct, FString identifier);

	UFUNCTION(BlueprintPure, Category = "save")
		static bool FileLoadString(FString FileNameA, FString& SaveTextA);
	
	
	
};
