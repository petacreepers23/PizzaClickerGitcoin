// Fill out your copyright notice in the Description page of Project Settings.

#include "AutomaticClickerActor.h"

#include "TimerManager.h"
#include "ClickerTestGameModeBase.h"

// Sets default values
AAutomaticClickerActor::AAutomaticClickerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAutomaticClickerActor::BeginPlay()
{
	Super::BeginPlay();

	
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AAutomaticClickerActor::Click, 1.0f, true,  0.5f);

	
}

// Called every frame
void AAutomaticClickerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	

}


//void AAutomaticClickerActor::NotifyActorOnClicked(FKey ButtonPressed) {
//	Super::NotifyActorOnClicked(ButtonPressed);
//
//	GetWorld()->GetAuthGameMode<AClickerTestGameModeBase>()->inc_global_pizzas();
//
//	if (GEngine) {
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
//			FString::Printf(TEXT("Automatic Pizzas: %d"), GetWorld()->GetAuthGameMode<AClickerTestGameModeBase>()->get_global_pizzas()));
//	}
//
//	//TODO: get gamemode add pizzas o lo q sea
//}




void AAutomaticClickerActor::Click()
{
	int NumerOfClicks = CalculateClick();
	GetWorld()->GetAuthGameMode<AClickerTestGameModeBase>()->inc_global_pizzas(NumerOfClicks);
	
	
	//if (GEngine) {
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
	//		FString::Printf(TEXT("Automatic Pizzas: %d"), GetWorld()->GetAuthGameMode<AClickerTestGameModeBase>()->get_global_pizzas()));
	//}

}


void AAutomaticClickerActor::MultiplicateBaseSpeed(float multiplicator)
{
	BaseClickSpeed *= multiplicator;
}

int AAutomaticClickerActor::CalculateClick()
{
	int ClickSpeed = BaseClickSpeed;// + bonifications etc..

	return ClickSpeed * NumerOfInstances;
}

void AAutomaticClickerActor::AddNumberOfInstances(int32 n)
{
	NumerOfInstances += n;
}
