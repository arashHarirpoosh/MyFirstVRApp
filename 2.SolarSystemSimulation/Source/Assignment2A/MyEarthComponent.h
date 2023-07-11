// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "MyEarthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASSIGNMENT2A_API UMyEarthComponent : public USceneComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		AActor* Sun;
	UPROPERTY(EditAnywhere)
		AActor* Moon;

public:	
	// Sets default values for this component's properties
	UMyEarthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		URotatingMovementComponent* rmc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmComp;
		
};
