// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	

	

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank =GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControllerTank = GetPawn();

	if (!ensure(PlayerTank && ControllerTank))
	{
		return;
	}
	
		
	MoveToActor(PlayerTank, AcceptanceRadius);

	auto AimingComponent = ControllerTank->FindComponentByClass<UTankAimingComponent>();
		
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	
	AimingComponent->Fire();
	
	

}


