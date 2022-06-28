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
	//virtual void Tick(float DeltaTime) override;
	//virtual void NotifyActorOnClicked(FKey ButtonPressed) override;
	
	/*
	* Activate the automatic clicker so it will start clicking every second.
	* WARNING: To execute this function the class must be spawned or it will
	* crash.
	* GetWorldTimerManager() will get a null pointer.
	*/
	void Activate();


	bool IsActivated();
	int32 GetPrice();
	void UpdatePrice();


	/*
	* Update Base Click speed with a multiplicator
	* 
	* Example duplicate de Base Speed.
	* MultiplicateBaseSpeed(2);
	*/
	void MultiplicateBaseSpeed(float multiplicator);

	/*
	* Calculate de number of total clicks per second
	*/
	int CalculateClick();


	int AddNumberOfInstances(int32 n);

	int32 GetNumberOfInstances();

	

protected:
	// important data
	UPROPERTY(EditAnywhere)
		FName Name;

	UPROPERTY(EditAnywhere)
		FName Description;

	UPROPERTY(EditAnywhere)
		uint32 Price {
		20
	};

	UPROPERTY(EditAnywhere)
		float PriceMultiplier{ 1.15 };

	UPROPERTY(EditAnywhere)
		int32 BaseClickSpeed {1};

	UPROPERTY(VisibleAnywhere)
		int32 NumerOfInstances {
		0
	};

	//TODO: this will overflow, some day....
	UPROPERTY(EditAnywhere)
		int64 NumerOfTotalClicks {
		0
	};

	UPROPERTY(EditAnywhere)
		bool Activated{ false };

	UFUNCTION()
	void Click();
private:
	FTimerHandle TimerHandle;







};
