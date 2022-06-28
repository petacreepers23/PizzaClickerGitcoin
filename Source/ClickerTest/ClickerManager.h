// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Buildings/AutomaticBaker.h"
#include "Buildings/AutomaticBar.h"
#include "Buildings/AutomaticFranchise.h"

#include "AutomaticsConstants.h"
#include "AutomaticClickerActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ClickerManager.generated.h"

UCLASS()
class CLICKERTEST_API AClickerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClickerManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//void addBuilding(BuildingType Type);
	int32 GetNumberOfInstances(BuildingType Type);
	int32 BuyBuilding(BuildingType Type, int32 Quantity);
	bool SellBuilding(BuildingType Type, int32 Quantity);
	int32 GetPrice(BuildingType Type);

	void ApplyUpgrade(float Multiplier);

private:
	UPROPERTY(VisibleAnywhere)
		TMap<BuildingType, AAutomaticClickerActor*> Buildings;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AAutomaticBaker> ActorToSpawn;

	UPROPERTY()
		AAutomaticBaker* Baker;

};
