// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
	{
		return;
	}
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntentMoveForward(float Throw)
{
	//auto name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Intent move forward throw: %f"), Throw)

	LeftTrack->SetTrackThrottle(Throw);
	RightTrack->SetTrackThrottle(Throw);
}
void UTankMovementComponent::IntentMoveBack(float Throw)
{
	//auto name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Intent move forward throw: %f"), Throw)

	LeftTrack->SetTrackThrottle(-Throw);
	RightTrack->SetTrackThrottle(-Throw);
}
void UTankMovementComponent::IntentTurnRight(float Throw)
{
	//auto name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Intent move forward throw: %f"), Throw)

	LeftTrack->SetTrackThrottle(Throw);
	RightTrack->SetTrackThrottle(-Throw);
}
void UTankMovementComponent::IntentTurnLeft(float Throw)
{
	//auto name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Intent move forward throw: %f"), Throw)

	LeftTrack->SetTrackThrottle(-Throw);
	RightTrack->SetTrackThrottle(Throw);
}