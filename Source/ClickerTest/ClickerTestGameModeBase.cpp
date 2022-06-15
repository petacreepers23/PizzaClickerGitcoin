// Copyright Epic Games, Inc. All Rights Reserved.


#include "ClickerTestGameModeBase.h"
#include "ClickerGameStateBase.h"

AClickerTestGameModeBase::AClickerTestGameModeBase() {

}


int32 AClickerTestGameModeBase::get_global_pizzas() {
	return GetGameState<AClickerGameStateBase>()->pizzas;
}
void AClickerTestGameModeBase::set_global_pizzas(int32 nuevas) {
	GetGameState<AClickerGameStateBase>()->pizzas = nuevas;
}
void AClickerTestGameModeBase::inc_global_pizzas() {
	GetGameState<AClickerGameStateBase>()->pizzas++;
}