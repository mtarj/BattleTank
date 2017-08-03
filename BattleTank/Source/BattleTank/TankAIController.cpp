// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not found Player Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player Tank: %s"), *(PlayerTank->GetName()))
	}

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector playerLocation;

	// Get Player Location
	ATank* playerTank = GetPlayerTank();
	if (playerTank)
	{
		playerLocation = playerTank->GetActorLocation();
		ATank* tank = GetControllerTank();
		if (tank)
		{
			//tank->AimAt(playerLocation);
		}
		//UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController ticking"))
	}

}

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerPawn);
	}

	

}
