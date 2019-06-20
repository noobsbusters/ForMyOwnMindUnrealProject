// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/Classes/Components/SphereComponent.h"

// Sets default values
AProjectile::AProjectile()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Collision
	//sphereCollision = CreateDefaultSubobject<USphereComponent>(FName("SphereCollision"));
	//sphereCollision->InitSphereRadius;
	//sphereCollision->InitSphereRadius(1);
	//sphereCollision->BodyInstance.SetCollisionProfileName(FName("Projectile"));
	//RootComponent = sphereCollision;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement Component"));
	//ProjectileMovementComponent->UpdatedComponent = sphereCollision;
	ProjectileMovementComponent->InitialSpeed = 1000;
	ProjectileMovementComponent->MaxSpeed = 10000;
	//ProjectileMovementComponent->bRotationFollowsVelocity = true;
	//ProjectileMovementComponent->bShouldBounce = false;
	ProjectileMovementComponent->bEditableWhenInherited = true;
	ProjectileMovementComponent->bAutoActivate = false;
	ProjectileMovementComponent->ProjectileGravityScale = 0;

	//sphereCollision->BodyInstance.SetEnableGravity(false);

	//InitialLifeSpan = 3;
}

void AProjectile::LaunchProjectile(float Speed)
{
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::RightVector * Speed);
	ProjectileMovementComponent->Activate();
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

