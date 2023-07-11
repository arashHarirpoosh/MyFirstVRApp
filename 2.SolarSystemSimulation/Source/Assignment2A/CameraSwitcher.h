// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "GameFramework/Actor.h"
#include "CameraSwitcher.generated.h"

UCLASS()
class ASSIGNMENT2A_API ACameraSwitcher : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		AActor* CameraOne;

	UPROPERTY(EditAnywhere)
		AActor* CameraTwo;
	UPROPERTY(EditAnywhere, Category = "Input | Actions")
		UInputAction* IA_KB_Move_InOut;

	float TimeToNextCameraChange;
	
public:	
	// Sets default values for this actor's properties
	ACameraSwitcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
