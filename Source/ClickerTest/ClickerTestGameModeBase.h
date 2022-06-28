// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "ClickerManager.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ClickerTestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CLICKERTEST_API AClickerTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	AClickerTestGameModeBase();
	

	virtual ~AClickerTestGameModeBase() = default;
	
	int32 get_global_pizzas();
	void set_global_pizzas(int32 nuevas);
	void inc_global_pizzas();
	void inc_global_pizzas(int32 nuevas);

private:
	UPROPERTY(VisibleAnywhere)
	AClickerManager* a;
};
