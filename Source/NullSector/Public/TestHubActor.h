// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTestActor.h"
#include "TestHubActor.generated.h"

UCLASS()
class NULLSECTOR_API ATestHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMyTestActor> TestClass;

	UPROPERTY(EditAnywhere)
	UClass* Class;

	UPROPERTY(EditAnywhere)
	AMyTestActor* TestObject;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
