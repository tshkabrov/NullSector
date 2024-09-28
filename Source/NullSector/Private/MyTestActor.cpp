// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor.h"

// Sets default values
AMyTestActor::AMyTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTestActor::BeginPlay()
{
	Super::BeginPlay();

	PrintTypes();
}

// Called every frame
void AMyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTestActor::PrintTypes() 
{
	UE_LOG(LogTemp, Display, TEXT("Begin play"));
	UE_LOG(LogTemp, Warning, TEXT("Begin play"));
	UE_LOG(LogTemp, Error, TEXT("Begin play"));
}


