// Fill out your copyright notice in the Description page of Project Settings.

#include "AimComponent.h"

// Sets default values for this component's properties
UAimComponent::UAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UAimComponent::SetTargetAimDirectionAndAngle(const float AimV, const float AimH)
{

	//celowanie prawo
	if (AimH > 0)
	{
		TargetAimDirection = 0;
		if (AimV > 0)
		{
			TargetAimAngle = 45;
		}
		else if (AimV < 0)
		{
			TargetAimAngle = -45;
		}
		else
		{
			TargetAimAngle = 0;
		}
	}
	//celowanie lewo
	else if(AimH < 0)
	{
		TargetAimDirection = -179.99f;
		if (AimV > 0)
		{
			TargetAimAngle = 45;
		}
		else if (AimV < 0)
		{
			TargetAimAngle = -45;
		}
		else
		{
			TargetAimAngle = 0;
		}
	}
	//celowanie default, ostatni klikniety kierunek
	else
	{
		if (AimV > 0)
		{
			TargetAimAngle = 90;
		}
		else if (AimV < 0)
		{
			TargetAimAngle = -90;
		}
		else
		{
			TargetAimAngle = 0;
		}
	}
}

void UAimComponent::CalculateCurrentAimDirectionAndAngle(float DeltaSeconds, float & Aim_Direction, float & Aim_Angle)
{


	CurrentAimAngle = FMath::FInterpTo(CurrentAimAngle, TargetAimAngle, DeltaSeconds, 15);
	CurrentAimDirection = FMath::FInterpTo(CurrentAimDirection, TargetAimDirection, DeltaSeconds, 15);

	Aim_Direction = CurrentAimDirection;
	Aim_Angle = CurrentAimAngle;
}

void UAimComponent::UpdateCurrentAimDirection(float NewCurrentRotation)
{

	 CurrentAimDirection = NewCurrentRotation ;
}

