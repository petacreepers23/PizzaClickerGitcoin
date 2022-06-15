// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ClickerGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class CLICKERTEST_API AClickerGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	AClickerGameStateBase();
	virtual ~AClickerGameStateBase() = default;

	int32 pizzas;
};
