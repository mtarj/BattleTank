// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto controllerTank = GetControllerTank();

	if (!controllerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller not possesing a tank "))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller possesing: %s"), *(controllerTank->GetName()))
	}
	
}

ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}
