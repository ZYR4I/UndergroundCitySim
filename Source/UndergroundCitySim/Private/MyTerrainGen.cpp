// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "MyTerrainGen.h"

// Sets default values
AMyTerrainGen::AMyTerrainGen()
{

	groundMeshes = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>
	(TEXT("groundMeshes"));

	ConstructorHelpers::FClassFinder<AMyWallCollision>wallCollisionBP(TEXT("/Game/Blueptints/WorldGen/BP_EnhancedWallCollision"));
	wallCollision = wallCollisionBP.Class;
	if (wallCollision = NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("This shouldnt work"));
	}
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AMyTerrainGen::PopulateGrid()
{
	gridPoints.Empty();
	worldOffset = ((gridSize * worldGridSize * 0.5) - (worldGridSize * 0.5));
	
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			FVector tempVector = FVector((j*worldGridSize)- FMath::FloorToInt(worldOffset), (i * worldGridSize) - FMath::FloorToInt(worldOffset), 0);
			gridPoints.Push(tempVector);
			//AActor* NewActor = GetWorld()->SpawnActor(wallCollision->StaticClass(), tempVector, FRotator(0,0,0), spawnInfo);
			AMyWallCollision* newWallCollision = GetWorld()->SpawnActor<AMyWallCollision>(wallCollision, tempVector, FRotator(0, 0, 0), spawnInfo);
			newWallCollision->Index = i * j;

			if ((i <= 2 || j <= 2 || i >= gridSize - 2 || j >= gridSize - 2))
			{
				newWallCollision->wallMaxHealth = 100;
				continue;
			}

			if ((i <= 3 || j <= 3 || i >= gridSize - 3 || j >= gridSize - 3))
			{
				newWallCollision->wallMaxHealth = 75;
				continue;
			}

			else
			{
				newWallCollision->wallMaxHealth = 50;
			}
		}
	}
}

void AMyTerrainGen::clearGrid()
{
	gridPoints.Empty();
	groundMeshes->ClearInstances();
}

void AMyTerrainGen::hismPop()
{
	groundMeshes->ClearInstances();

	for (FVector point : gridPoints)
	{
		FTransform temp = FTransform(FRotator(0, 0, 0), point, FVector(2, 2, 2));
		groundMeshes->AddInstance(temp, true);
	}
}

// Called when the game starts or when spawned
void AMyTerrainGen::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTerrainGen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

