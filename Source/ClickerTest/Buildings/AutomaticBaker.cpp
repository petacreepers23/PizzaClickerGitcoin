// Fill out your copyright notice in the Description page of Project Settings.


#include "AutomaticBaker.h"

AAutomaticBaker::AAutomaticBaker()
{
	//PrimaryActorTick.bCanEverTick = true;
	Price = 25;
	BaseClickSpeed = 1;
}

void AAutomaticBaker::BeginPlay()
{
	Super::BeginPlay();


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BAKER!"));
}
