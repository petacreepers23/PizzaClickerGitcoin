// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AutomaticClickerActor.generated.h"

UCLASS()
class CLICKERTEST_API AAutomaticClickerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutomaticClickerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//virtual void NotifyActorOnClicked(FKey ButtonPressed) override;
	
	






	/*
	* Update Base Click speed with a multiplicator
	* 
	* Example duplicate de Base Speed.
	* MultiplicateBaseSpeed(2);
	*/
	void MultiplicateBaseSpeed(float multiplicator);

	
	//virtual void IncrementInstance(int number) ;


	UFUNCTION()
	void Click();

	/*
	* Calculate de number of total clicks per second
	*/
	int CalculateClick();
	
	void AddNumberOfInstances(int32 n);

private:
	FTimerHandle TimerHandle;




	// important data
	UPROPERTY(EditAnywhere)
		FName Name;

	UPROPERTY(EditAnywhere)
		FName Description;

	UPROPERTY(EditAnywhere)
		uint32 Price;

	UPROPERTY(EditAnywhere)
		float PriceMultiplier{1.15};

	UPROPERTY(EditAnywhere)
		int32 BaseClickSpeed {10};

	UPROPERTY(VisibleAnywhere)
		int32 NumerOfInstances{1};

	//TODO: this will overflow, some day....
	UPROPERTY(EditAnywhere)
		int64 NumerOfTotalClicks {0};





};
