// Fill out your copyright notice in the Description page of Project Settings.

#include "ClickerManager.h"


#include "Pizzero.h"
#include "ClickerTestGameModeBase.h"
#include "TimerManager.h"

// Sets default values
AClickerManager::AClickerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;




	// TODO: See where the initialization of the game shoud go. In case this action is going to be always at the start maybe then
	// can be added without a method or in compile time.

	//addBuilding(BuildingType::Baker);
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
		FString::Printf(TEXT("Manager inicializado")));
	}

}

// Called when the game starts or when spawned
void AClickerManager::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
	FString::Printf(TEXT("Manager Begin")));
;


	Baker = GetWorld()->SpawnActor<AAutomaticBaker>(AAutomaticBaker::StaticClass());
	Buildings.Add(BuildingType::Baker, Baker);
	Buildings.Add(BuildingType::Bar, GetWorld()->SpawnActor<AAutomaticBar>(AAutomaticBar::StaticClass()));
	Buildings.Add(BuildingType::Franchise, GetWorld()->SpawnActor<AAutomaticFranchise>(AAutomaticFranchise::StaticClass()));

	//AutomaticClicker->CalculateClick();
	//GetWorldTimerManager().SetTimer(TimerHandle, AutomaticClicker, &AAutomaticClickerActor::Click, 1.0f, true, 0.5f);
	
}



// Called every frame
void AClickerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}







//void AClickerManager::addBuilding(BuildingType Type)
//{
//	AAutomaticClickerActor* AutomaticClicker;
//	switch (Type)
//	{
//	case BuildingType::Baker:
//		AutomaticClicker = NewObject<AAutomaticBaker>();
//		AutomaticClicker->CalculateClick();
//		// This will explote if not spawnded, getworld, give a null
//		//GetWorldTimerManager().SetTimer(TimerHandle, AutomaticClicker, &AAutomaticClickerActor::Click, 1.0f, true, 0.5f);
//		break;
//	case BuildingType::Bar:
//		AutomaticClicker = NewObject<AAutomaticBar>();
//		break;
//	case BuildingType::Pizzero:
//		AutomaticClicker = NewObject<APizzero>();
//		break;
//	default:
//		break;
//	}
//
//	Buildings.Add(Type, AutomaticClicker);
//	if (Buildings.Contains(Type)) {
//
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("a�aido edificio?"));
//		//Buildings[Type]->CalculateClick();
//		//GetWorldTimerManager().SetTimer(TimerHandle, Buildings[Type], &AAutomaticClickerActor::Click, 1.0f, true, 0.5f);
//	}
//}



int32 AClickerManager::GetNumberOfInstances(BuildingType Type)
{
	return Buildings[Type]->GetNumberOfInstances();
}

int32 AClickerManager::BuyBuilding(BuildingType Type, int32 Quantity)
{
	/*int32 CurrentClicks = GetWorld()->GetAuthGameMode<AClickerTestGameModeBase>()->get_global_pizzas();*/
	if (!Buildings.Contains(Type)) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
			FString::Printf(TEXT("Estas intentando comprar un edificio que no existe")));
		return false;
	}
	Buildings[Type]->Activate();
	int32 NumberOfInstances = Buildings[Type]->AddNumberOfInstances(Quantity);
	Buildings[Type]->UpdatePrice();
	return NumberOfInstances;
}

bool AClickerManager::SellBuilding( BuildingType Type, int32 Quantity)
{
	if (!Buildings.Contains(Type)) {
		return false;
	}
	Buildings[Type]->AddNumberOfInstances(Quantity);
	return true;
}

int32 AClickerManager::GetPrice(BuildingType Type)
{
	if (!Buildings.Contains(Type)) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
			FString::Printf(TEXT("PRICE: Este edificio no existe")));
		return 999999;
	}
	return Buildings[Type]->GetPrice();

}

void AClickerManager::ApplyUpgrade(float Multiplier)
{
	for (const TPair<BuildingType, AAutomaticClickerActor*>& pair : Buildings) {
		pair.Value->MultiplicateBaseSpeed(Multiplier);
	}

}
