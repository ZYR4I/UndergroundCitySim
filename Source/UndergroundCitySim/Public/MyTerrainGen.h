// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "MyWallCollision.h"
#include "MyTerrainGen.generated.h"

//declaring
class UHierarchicalInstancedStaticMeshComponent;



UCLASS()
class UNDERGROUNDCITYSIM_API AMyTerrainGen : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTerrainGen();

	//functions

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Grid")
	void PopulateGrid();

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Grid")
	void clearGrid();

	UFUNCTION(BlueprintCallable,CallInEditor, Category = "Grid")
	void hismPop();

	//Hism
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hism", meta = (AllowPrivateAccess = "true"))
	class UHierarchicalInstancedStaticMeshComponent* groundMeshes;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid", meta = (AllowPrivateAccess = "true"))
	int gridSize = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid", meta = (AllowPrivateAccess = "true"))
	int worldGridSize = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Data", meta = (AllowPrivateAccess = "true"))
	TArray<FVector> gridPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid|Data", meta = (AllowPrivateAccess = "true"))
	float worldOffset = 0;

	UPROPERTY(VisibleAnywhere)
	TSubclassOf<AMyWallCollision> wallCollision;
	

	FActorSpawnParameters spawnInfo;
};
