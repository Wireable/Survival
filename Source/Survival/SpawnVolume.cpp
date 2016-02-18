// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	WhereToSpawn = CreateDefaultSubobject<USphereComponent>(TEXT("Spawn area"));
	
	RootComponent = WhereToSpawn;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolume::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


FVector ASpawnVolume::GetRandomPointInVolume()
{
	
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
	float radius = WhereToSpawn->Bounds.SphereRadius;
	float t = 2 * UKismetMathLibrary::GetPI()*UKismetMathLibrary::RandomFloatInRange(0, 1)*radius;
	float u = radius * UKismetMathLibrary::Sqrt(UKismetMathLibrary::RandomFloatInRange(0, 1));
	float r;
	if (u > 1)
	{
		r = 2 - u;
	}
	else
	{
		r = u;
	}

	//float r = radius*UKismetMathLibrary::RandomFloatInRange(0,1);
	float x = SpawnOrigin.X + r*cos(t);
	float y = SpawnOrigin.Y + r*sin(t);
	//FVector point = 
	return FVector(x, y, SpawnOrigin.Z);

}

