// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MyTestActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static,
};

USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Movement")
	EMovementType MoveType = EMovementType::Static;

	UPROPERTY(EditAnywhere)
	float Amplitude = 50.0F;

	UPROPERTY(EditAnywhere)
	float Frequency = 2.0f;
	UPROPERTY(EditAnywhere)
	FLinearColor Color = FLinearColor::Black;
};

UCLASS()
class NULLSECTOR_API AMyTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTestActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category= "Geometry")
	FGeometryData GeometryData;

	UPROPERTY(EditAnywhere)
	int32 Ammo = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	float Health = 100;

	UPROPERTY(EditInstanceOnly)
	float Damage = 10;

	UPROPERTY(EditAnywhere)
	bool IsDead = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void PrintTypes();

	FVector InitialLocation;
};

