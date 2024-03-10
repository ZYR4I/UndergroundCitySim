// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWallCollision.h"

// Sets default values
AMyWallCollision::AMyWallCollision()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyWallCollision::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyWallCollision::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

