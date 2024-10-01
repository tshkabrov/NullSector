// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"

// Sets default values
AMyTestActor::AMyTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void AMyTestActor::BeginPlay()
{
	Super::BeginPlay();

	//print string
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, GetName());

	InitialLocation = GetActorLocation();

	SetColor(GeometryData.Color);
	PrintTypes();

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyTestActor::OnTimerFire, TimerRate, true);

	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogTemp, Warning, TEXT("Actor name %s"), *GetName());
	UE_LOG(LogTemp, Warning, TEXT("Transform %s"), *Transform.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Location %s"), *Location.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Rotation %s"), *Rotation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Scale %s"), *Scale.ToString());

	UE_LOG(LogTemp, Error, TEXT("Human Transform %s"), *Transform.ToHumanReadableString());

}

// Called every frame
void AMyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (GeometryData.MoveType)
	{
	case EMovementType::Sin:
	{
		// sinus move
		FVector CurrentLocation = GetActorLocation();
		float time = GetWorld()->GetTimeSeconds();
		CurrentLocation.Z = InitialLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Frequency * time);
		SetActorLocation(CurrentLocation);
	}
		break;
	case EMovementType::Static:
		break;
	default:
		break;
	}
		
}

void AMyTestActor::PrintTypes() 
{
	UE_LOG(LogTemp, Display, TEXT("Begin play"));
	UE_LOG(LogTemp, Warning, TEXT("Begin play"));
	UE_LOG(LogTemp, Error, TEXT("Begin play"));
}

void AMyTestActor::SetColor(const FLinearColor& Color)
{
	UMaterialInstanceDynamic* DynMaterial = BaseMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynMaterial)
	{ 
		DynMaterial->SetVectorParameterValue("Color", Color);
	}
}

void AMyTestActor::OnTimerFire()
{
	if (++TimerCount <= MaxTimerCount)
	{
		const FLinearColor NewColor = FLinearColor::MakeRandomColor();
		SetColor(NewColor);
		// GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, NewColor, true, FVector2D(1.5f, 1.5f));
	}
	else
	{
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}


