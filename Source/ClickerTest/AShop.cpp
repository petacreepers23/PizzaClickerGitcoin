// Fill out your copyright notice in the Description page of Project Settings.


#include "AShop.h"
#include "ClickerTestGameModeBase.h"
#include "Pizzero.h"
// Sets default values
AAShop::AAShop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AAShop::BeginPlay()
{
	Super::BeginPlay();
	ClickerManager = GetWorld()->SpawnActor<AClickerManager>(AClickerManager::StaticClass());

	// activate here so tick will not execute earlier than BeginPlay, and the ClickerManager is not nullptr.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called every frame
void AAShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAShop::ApplyUpgrade(float Multiplier)
{
	return ClickerManager->ApplyUpgrade(Multiplier);
}

int32 AAShop::GetPrice(BuildingType Type)
{
	
	//if (ClickerManager == nullptr) {
	//	return 0;

	//}	
	return ClickerManager->GetPrice(Type);
}



int32 AAShop::BuyBuilding(int32 CurrentClicks, BuildingType Type, int32 Quantity)
{
	//int32 CurrentClicks = GetWorld()->GetAuthGameMode<AClickerTestGameModeBase>()->get_global_pizzas();

	int32 Price = ClickerManager->GetPrice(Type);
	if ( CurrentClicks < Price)   {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Pobreee"));
		return ClickerManager->GetNumberOfInstances(Type);
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BUY in SHOP"));
	GetWorld()->GetAuthGameMode<AClickerTestGameModeBase>()->inc_global_pizzas(-1 * Price);
	UE_LOG(LogTemp, Warning, TEXT("Price %d"), Price);

	// call to do operation.
	
	return ClickerManager->BuyBuilding(Type, Quantity);
}

bool AAShop::SellBuilding(int32 Price, BuildingType Type, int32 Quantity)
{
	//if ( !Buildings.Contains(Type) ) {
	//	return false;
	//}
	//Buildings[Type]->AddNumberOfInstances(Quantity);
	return true;
}



