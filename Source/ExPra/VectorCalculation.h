// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "VectorCalculation.generated.h"

/**
 * 
 */
UCLASS()
class EXPRA_API UVectorCalculation : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable, Category = "vectorCalc")
		static FVector myRotationOffset(FVector cameraPoint, FVector cameraForwardVector, FVector boxPlaneNormalVector, FVector boxPlanePoint);
		static float myVectorLength(FVector v);
		static float dotProdukt(FVector a, FVector b);
		static FVector add(FVector a, FVector b);
		static FVector minus(FVector a, FVector b);
		static FVector mult(FVector a, float f);
};
