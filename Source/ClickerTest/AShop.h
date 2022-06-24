// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AutomaticsConstants.h"
#include "AutomaticClickerActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AShop.generated.h"





UCLASS()
class CLICKERTEST_API AAShop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAShop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// used firt time 
	//void makeBuilding();











	void addBuilding(BuildingType Type);




	bool BuyBuilding(int32 CurrentClicks, int32 Price, BuildingType Type, int32 Quantity);
	//bool BuyBuilding(int32 CurrentClicks, tipe of object, int32 Quantity=1);

	bool SellBuilding(int32 Price, BuildingType Type, int32 Quantity);
private:
	TMap<BuildingType, AAutomaticClickerActor*> Buildings;


};
