// Fill out your copyright notice in the Description page of Project Settings.

#include "ExPra.h"
#include "VectorCalculation.h"

FVector UVectorCalculation::myRotationOffset(FVector cameraPoint, FVector cameraNormalVector, FVector boxPlaneNormalVector, FVector boxPlanePoint) {
	float offRoll, offYaw, offPitch;
	offRoll = 0;
	// calculate if camera is facing the box plane
	if (dotProdukt(boxPlaneNormalVector, cameraNormalVector) == 0) {
		// camera not facing the boxplane
		offYaw = 0, offPitch = 0;
	}
	else {
		// camera is facing the box plane, calc point in plane that the camera line intersects
		float d = dotProdukt(minus(boxPlanePoint, cameraPoint), boxPlaneNormalVector) / dotProdukt(cameraNormalVector, boxPlaneNormalVector);
		FVector intersectionPoint = add(mult(cameraNormalVector, d), cameraPoint);

		// calc Yaw offset(x and y need, zero out z)
		FVector a(boxPlanePoint.X, boxPlanePoint.Y, 0);
		FVector b(cameraPoint.X, cameraPoint.Y, 0);
		FVector c(intersectionPoint.X, intersectionPoint.Y, 0);

		offYaw = atan(myVectorLength(minus(a, c)) / myVectorLength(minus(b, c)));

		// calc Pitch((cameraPoint, pointInBoxPlaneXYFromBoxPointHeightCamera))
		FVector pointInBoxPlane(boxPlanePoint.X, boxPlanePoint.Y, cameraPoint.Z);
		// camera
		// boxPlanePoint
		offPitch = atan(myVectorLength(minus(boxPlanePoint, pointInBoxPlane)) / myVectorLength(minus(cameraPoint, boxPlanePoint)));
		
	}
	

	//return FVector(offRoll, offYaw, offPitch);
	return FVector(100, 100, 100);
}

float UVectorCalculation::myVectorLength(FVector v) {
	return sqrt((v.X * v.X) + (v.Y + v.Y) + (v.Z + v.Z));
}

float UVectorCalculation::dotProdukt(FVector a, FVector b) {
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

FVector UVectorCalculation::add(FVector a, FVector b) {
	return FVector(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
}

FVector UVectorCalculation::minus(FVector a, FVector b) {
	return FVector(a.X - b.X, a.Y - b.Y, a.Z - b.Z);
}

FVector UVectorCalculation::mult(FVector a, float f) {
	return FVector(a.X * f, a.Y * f, a.Z * f);
}