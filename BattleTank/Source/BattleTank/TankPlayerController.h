// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // mus be the last include

// FD
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


	
public:
	ATank* GetControllerTank() const;

	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
private:
	void AimTowarsCrosshair();
	bool GetSightRayHitLocation(FVector& out_hitLocation) const;
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333f;
	
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool  GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
};
