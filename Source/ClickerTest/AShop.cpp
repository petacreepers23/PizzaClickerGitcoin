// Fill out your copyright notice in the Description page of Project Settings.


#include "AShop.h"
#include "ClickerTestGameModeBase.h"
#include "Pizzero.h"
// Sets default values
AAShop::AAShop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAShop::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAShop::addBuilding(BuildingType Type)
{
	AAutomaticClickerActor* AutomaticClicker;
	if(Type == BuildingType::Pizzero)
	{
		AutomaticClicker = NewObject<APizzero>();
	}
	
	Buildings.Add(Type, AutomaticClicker);
}

bool AAShop::BuyBuilding(int32 CurrentClicks, int32 Price, BuildingType Type, int32 Quantity)
{
	/*int32 CurrentClicks = GetWorld()->GetAuthGameMode<AClickerTestGameModeBase>()->get_global_pizzas();*/
	if ( (CurrentClicks < Price) && (!Buildings.Contains(Type) ) ) {
		return false;
	}
	Buildings[Type]->AddNumberOfInstances(Quantity);
	return true;
}

bool AAShop::SellBuilding(int32 Price, BuildingType Type, int32 Quantity)
{
	if ( !Buildings.Contains(Type) ) {
		return false;
	}
	Buildings[Type]->AddNumberOfInstances(Quantity);
	return true;
}



