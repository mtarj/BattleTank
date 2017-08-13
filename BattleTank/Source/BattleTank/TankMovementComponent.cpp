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
	LeftTrack->SetTrackThrottle(Throw);
	RightTrack->SetTrackThrottle(Throw);
}
void UTankMovementComponent::IntentMoveBack(float Throw)
{
	LeftTrack->SetTrackThrottle(-Throw);
	RightTrack->SetTrackThrottle(-Throw);
}
void UTankMovementComponent::IntentTurnRight(float Throw)
{
	LeftTrack->SetTrackThrottle(Throw);
	RightTrack->SetTrackThrottle(-Throw);
}
void UTankMovementComponent::IntentTurnLeft(float Throw)
{
	LeftTrack->SetTrackThrottle(-Throw);
	RightTrack->SetTrackThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntentMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntentTurnRight(RightThrow);
	
}
