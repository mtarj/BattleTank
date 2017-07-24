// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto controllerTank = GetControllerTank();

	if (!controllerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possesing a tank "))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possesing: %s"), *(controllerTank->GetName()))
	}

}

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

