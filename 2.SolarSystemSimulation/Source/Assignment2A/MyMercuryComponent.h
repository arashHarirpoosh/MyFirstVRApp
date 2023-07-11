// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "MyMercuryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASSIGNMENT2A_API UMyMercuryComponent : public USceneComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		AActor* Sun;
public:	
	// Sets default values for this component's properties
	UMyMercuryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		URotatingMovementComponent* rmc;	
};
