// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntentMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntentMoveBack(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntentTurnRight(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntentTurnLeft(float Throw);
	UTankTrack* RightTrack = nullptr;
	UTankTrack* LeftTrack = nullptr;

private:
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
};
