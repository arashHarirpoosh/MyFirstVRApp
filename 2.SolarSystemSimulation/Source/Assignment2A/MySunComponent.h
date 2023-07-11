// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/SceneComponent.h"
#include "MySunComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASSIGNMENT2A_API UMySunComponent : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		AActor* Mercury;
	UPROPERTY(EditAnywhere)
		AActor* Venus;
	UPROPERTY(EditAnywhere)
		AActor* Earth;
	UPROPERTY(EditAnywhere)
		AActor* Mars;
	UPROPERTY(EditAnywhere)
		AActor* Jupiter;
	UPROPERTY(EditAnywhere)
		AActor* Saturn;
	UPROPERTY(EditAnywhere)
		AActor* Uranus;
	UPROPERTY(EditAnywhere)
		AActor* Neptune;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
		URotatingMovementComponent* RotatingMovement;*/

public:	
	// Sets default values for this component's properties
	UMySunComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		URotatingMovementComponent* rmc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmCompMercury;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmCompVenus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmCompEarth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmCompMars;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmCompJupiter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmCompSaturn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmCompUranus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmCompNeptune;
};
