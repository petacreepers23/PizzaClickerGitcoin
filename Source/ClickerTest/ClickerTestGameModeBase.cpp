// Copyright Epic Games, Inc. All Rights Reserved.

#include "ClickerTestGameModeBase.h"
#include "ClickerGameStateBase.h"
#include "ClickerManager.h"

AClickerTestGameModeBase::AClickerTestGameModeBase() {

	//a = CreateDefaultSubobject<AClickerManager>(TEXT("RootComponent"));
	 //a = NewObject<AClickerManager>();

	//AClickerManager* a = CreateDefaultSubobject<AClickerManager>(TEXT("RootComponent"));
	//a->addBuilding(BuildingType::Baker);
	//a->addBuilding(BuildingType::Bar);
	/*a->SpawnBuilding(BuildingType::Bar);*/
}


int32 AClickerTestGameModeBase::get_global_pizzas() {
	return GetGameState<AClickerGameStateBase>()->pizzas;
}
void AClickerTestGameModeBase::set_global_pizzas(int32 nuevas) {
	GetGameState<AClickerGameStateBase>()->pizzas = nuevas;
}
void AClickerTestGameModeBase::inc_global_pizzas() {
	//a->addBuilding(BuildingType::Baker);

	//a->SpawnBuilding(BuildingType::Bar);
	GetGameState<AClickerGameStateBase>()->pizzas++;
}
void AClickerTestGameModeBase::inc_global_pizzas(int32 nuevas) {
	GetGameState<AClickerGameStateBase>()->pizzas+=nuevas;
}