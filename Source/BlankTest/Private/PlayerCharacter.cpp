// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "AimComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCustomCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AimComponent = CreateDefaultSubobject<UAimComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

void APlayerCharacter::SetTargetAimDirectionAndAngle(float AimV, float AimH)
{
	AimComponent->SetTargetAimDirectionAndAngle(AimV, AimH);
}

void APlayerCharacter::CalculateCurrentAimDirectionAndAngle(float DeltaTime, float & Aim_Direction, float & Aim_Angle)
{
	AimComponent->CalculateCurrentAimDirectionAndAngle(DeltaTime, Aim_Direction, Aim_Angle);
}

void APlayerCharacter::UpdateCurrentAimDirection()
{
	
	FRotator ActorRotation = this->GetActorRotation();

	AimComponent->UpdateCurrentAimDirection(ActorRotation.Yaw);
}

