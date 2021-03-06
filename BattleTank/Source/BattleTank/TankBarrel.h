// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// +1 elevate at max speed / -1 down at max speed
	void Elevate(float RelativeSpeed);

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxElevationDegrees = 40.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MinElevationDegrees = 0.0f;

	
	
};
