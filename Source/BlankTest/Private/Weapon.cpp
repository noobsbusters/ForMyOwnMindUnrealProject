// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Projectile.h"
#include "Engine/World.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void AWeapon::Fire()
{
	//spawn projectile on projectile socket in the barrel
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		BulletBlueprint,
		WeaponMesh->GetSocketLocation(FName("BulletSpawn")),
		WeaponMesh->GetSocketRotation(FName("BulletSpawn"))
		);

	Projectile->LaunchProjectile(MuzzleVelocity);
}
void AWeapon::SetWeaponMesh(UStaticMeshComponent * MeshToSet)
{
	WeaponMesh = MeshToSet;
}
// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

