// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CustomCharacterMovementComponent.h"
#include "PlayerCharacter.generated.h"

class UAimComponent;

UCLASS()
class BLANKTEST_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UAimComponent * AimComponent = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Aim")
	void SetTargetAimDirectionAndAngle(float AimV, float AimH);

	UFUNCTION(BlueprintCallable, Category = "Aim")
	void CalculateCurrentAimDirectionAndAngle(float DeltaTime, float & Aim_Direction, float & Aim_Angle);

	UFUNCTION(BlueprintCallable, Category = "Aim")
	void UpdateCurrentAimDirection();

};
