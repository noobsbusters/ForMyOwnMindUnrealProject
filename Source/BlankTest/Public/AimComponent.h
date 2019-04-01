// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "AimComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLANKTEST_API UAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float CurrentAimDirection = 0;
	float TargetAimDirection = 0;

	float CurrentAimAngle = 0;
	float TargetAimAngle = 0;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetTargetAimDirectionAndAngle(const float AimV, const float AimH);

	void CalculateCurrentAimDirectionAndAngle(float DeltaSeconds, float &Aim_Direction, float &Aim_Angle);
		
	void UpdateCurrentAimDirection(float NewCurrentRotation);

};
