// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Weapon.generated.h"

class AProjectile;

UCLASS()
class BLANKTEST_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float RateOfFire = 100; // rounds/s

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float MuzzleVelocity = 5000; // rounds/s

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> BulletBlueprint = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void SetWeaponMesh(UStaticMeshComponent * MeshToSet);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UStaticMeshComponent * WeaponMesh = nullptr;

};
