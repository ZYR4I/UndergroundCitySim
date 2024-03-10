// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyWallCollision.generated.h"

UCLASS()
class UNDERGROUNDCITYSIM_API AMyWallCollision : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyWallCollision();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallStats", meta = (AllowPrivateAccess = "true"))
	int wallCurrentHealth = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallStats", meta = (AllowPrivateAccess = "true"))
	int wallMaxHealth = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallStats|Inherited", meta = (AllowPrivateAccess = "true"))
	int Index = 0;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallStats|Inherited", meta = (AllowPrivateAccess = "true"))
	//class AMyTerrainGen* gridRef;

};
