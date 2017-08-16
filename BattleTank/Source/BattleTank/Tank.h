// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // colocar los nuevos includes arriba de esta linea.

// FD
class UTankBarrel; 
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:

	

public:

	

	

	// Sets default values for this pawn's properties
	ATank();


	void BeginPlay() override;
	
	

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int testProp = 1;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int testProp2 = 2;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int testProp3 = 3;
		
	UFUNCTION(BlueprintCallable, Category = "Test")
	void TestFunc();
private:

	UTankBarrel* Barrel = nullptr; // TODO REMOVE
};
