// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHubActor.h"
#include "Engine/World.h"

// Sets default values
ATestHubActor::ATestHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestHubActor::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if (World)
	{
		for (int32 i = 0; i < 10; ++i)
		{
			const FTransform TestTransform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f * i, 300.0f));
			AMyTestActor* Test = World->SpawnActor<AMyTestActor>(TestClass, TestTransform);
			FGeometryData Data;
			Data.MoveType = FMath::RandBool() ? EMovementType::Static : EMovementType::Sin;
			Test->SetTestActorData(Data);
		}		
	}
}

// Called every frame
void ATestHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

