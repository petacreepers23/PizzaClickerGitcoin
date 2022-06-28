// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../AutomaticClickerActor.h"
#include "AutomaticBaker.generated.h"

/**
 * 
 */
UCLASS()
class CLICKERTEST_API AAutomaticBaker : public AAutomaticClickerActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAutomaticBaker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
