// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "CameraSwitcherHandler.generated.h"

UCLASS()
class ASSIGNMENT2A_API ACameraSwitcherHandler : public ACharacter
{
	GENERATED_BODY()

#pragma region input
	UPROPERTY(EditAnywhere)
		AActor* CameraOne;

	UPROPERTY(EditAnywhere)
		AActor* CameraTwo;
	UPROPERTY(EditAnywhere)
		AActor* CameraThree;
	UPROPERTY(EditAnywhere)
		AActor* CameraFour;
	UPROPERTY(EditAnywhere, Category = "Input | Actions")
		UInputAction* IA_SC;
	UPROPERTY(EditAnywhere, Category = "Input")
		TSoftObjectPtr<UInputMappingContext> IMC_Normal_Controls;

	float TimeToNextCameraChange;

public:
	// Sets default values for this character's properties
	ACameraSwitcherHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SwitchCamera(const FInputActionInstance& Instance);


};
