// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTestActor.generated.h"

UCLASS()
class NULLSECTOR_API AMyTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int Ammo = 0;
	float Health = 100;
	bool IsDead = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void PrintTypes();

};

