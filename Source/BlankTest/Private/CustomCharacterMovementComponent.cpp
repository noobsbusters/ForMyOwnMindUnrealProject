// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomCharacterMovementComponent.h"


//////////////////////////////////////////////////////////////////////////
// UVictoryCharMoveComp

UCustomCharacterMovementComponent::UCustomCharacterMovementComponent(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{

}

void UCustomCharacterMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();
	//~~~~~~~~~~~~~~~~~

	//UE_LOG //comp Init!
}

//Tick Comp
void UCustomCharacterMovementComponent::TickComponent(
	float DeltaTime,
	enum ELevelTick TickType,
	FActorComponentTickFunction *ThisTickFunction
)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//UE_LOG //custom comp is ticking!!!

}